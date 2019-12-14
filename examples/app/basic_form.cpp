#include "stdafx.h"
#include "basic_form.h"
#include "keycap.h"
#include "chart.h"

#define WM_USER_KEY WM_USER + 1

#define LOG(...) ::OutputDebugString((nbase::StringPrintf(__VA_ARGS__).append(_T("\n")).c_str()));

/**
 * ����ͼ
 * 1.Ϊÿ�����ݵ�����һ������������ҶȽ����Բ��
 * 2.���ûҶȿ��Ե��ӵ�ԭ������ÿ�����ص����ݽ�����ӵõ��ĻҶ�ֵ��
 * 3.����ÿ�����ؼ���õ��ĻҶ�ֵ����һ����ɫɫ���н�����ɫӳ�䣬����ͼ�������ɫ���õ�����ͼ��
 */
const std::wstring BasicForm::kClassName = L"Basic";

BasicForm::BasicForm()
{
}


BasicForm::~BasicForm()
{
}

std::wstring BasicForm::GetSkinFolder()
{
	return L"app";
}

std::wstring BasicForm::GetSkinFile()
{
	return L"app.xml";
}

std::wstring BasicForm::GetWindowClassName() const
{
	return kClassName; }

ui::Control* BasicForm::CreateControl(const std::wstring& pstrClass) {
  if (pstrClass.compare(_T("Keycap")) == 0) {
	  return new ui::Keycap();
	} else if (pstrClass.compare(_T("Chart")) == 0) {
    return new ui::ThermodynamicChart();
  }
  return nullptr;
}

LRESULT BasicForm::OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam,
                             BOOL& bHandled) {
  if (wParam == VK_ESCAPE) {
	  Close();
	}
  return false;
}

void BasicForm::InitWindow() {
  keyboard_hook_helper_.AddKeyboardEventListener(this);
}

LRESULT BasicForm::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	PostQuitMessage(0L);
	return __super::OnClose(uMsg, wParam, lParam, bHandled);
}

LRESULT BasicForm::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
  if (uMsg == WM_USER_KEY) {
    auto i = repo_.statistics.find(wParam);
    if (i != repo_.statistics.end()) {
      repo_.statistics[wParam] = i->second + 1;
    } else {
      repo_.statistics[wParam] = 1;
    }
    LOG(_T("%d"), repo_.statistics[wParam]);
  }
  return __super::HandleMessage(uMsg, wParam, lParam);
}

bool BasicForm::keyboardEvent(int nCode, WPARAM wParam, LPARAM lParam) {
  KBDLLHOOKSTRUCT* kbd = (KBDLLHOOKSTRUCT*)lParam;
  if (!(kbd->flags & LLKHF_UP)) {
    PostMessageW(WM_USER_KEY, (WPARAM)kbd->vkCode, 0);
  }
  return false;
}
