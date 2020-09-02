#include "stdafx.h"
#include "Hook.h"

//ȫ�ֱ���
static KeyboardHookHelper* helper;

//��̬��Ա
std::set<KeyboardHookHelper::KeyboardEventListener*>
    KeyboardHookHelper::mListenerList;

KeyboardHookHelper::KeyboardHookHelper() : mHook(NULL) {
  helper = this;
  setWindowsHook();
}

LRESULT KeyboardHookHelper::keyboardHookCallback(int nCode, WPARAM wParam,
                                         LPARAM lParam) {
  if (nCode >= HC_ACTION) {
    int r = 0;
    for (auto listener : helper->mListenerList) {
      if (listener->keyboardEvent(nCode, wParam, lParam)) {
        ++r;
      }
    }
    if (r > 0) {
      return true;
    }
  }
  return (CallNextHookEx(helper->mHook, nCode, wParam, lParam));
}

bool KeyboardHookHelper::AddKeyboardEventListener(
    KeyboardEventListener* listener) {
  if (listener == NULL) {
    return false;
  }
  mListenerList.insert(listener);
  return true;
}

KeyboardHookHelper::~KeyboardHookHelper() {
  if (mHook) {
    UnhookWindowsHookEx(mHook);
    mHook = NULL;  //   ж������
  }
  mListenerList.clear();
  helper = NULL;
}

bool KeyboardHookHelper::setWindowsHook() {
  if (mHook == NULL) {
    //��װ�¹���
    mHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)keyboardHookCallback,
                             GetModuleHandle(NULL), 0);
  }
  return mHook != NULL;
}
