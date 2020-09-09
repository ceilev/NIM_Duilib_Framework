#pragma once
#include "stdafx.h"

#include "hook.h"
#include "repo.h"
#include <mutex>

class BasicForm : public ui::WindowImplBase, public KeyboardHookHelper::KeyboardEventListener
{
public:
	BasicForm();
	~BasicForm();

	/**
	 * ���������ӿ��Ǳ���Ҫ��д�Ľӿڣ����������������ӿ�����������
	 * GetSkinFolder		�ӿ�������Ҫ���ƵĴ���Ƥ����Դ·��
	 * GetSkinFile			�ӿ�������Ҫ���ƵĴ��ڵ� xml �����ļ�
	 * GetWindowClassName	�ӿ����ô���Ψһ��������
	 */
	virtual std::wstring GetSkinFolder() override;
	virtual std::wstring GetSkinFile() override;
	virtual std::wstring GetWindowClassName() const override;

	virtual ui::Control* CreateControl(const std::wstring& pstrClass) override;

	virtual LRESULT OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	/**
	 * �յ� WM_CREATE ��Ϣʱ�ú����ᱻ���ã�ͨ����һЩ�ؼ���ʼ���Ĳ���
	 */
	virtual void InitWindow() override;

	/**
	 * �յ� WM_CLOSE ��Ϣʱ�ú����ᱻ����
	 */
	virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;




  virtual bool keyboardEvent(int nCode, WPARAM wParam, LPARAM lParam) override;


  void CheckThread();

	static const std::wstring kClassName;
	KeyboardHookHelper keyboard_hook_helper_;
	Repo repo_;
  std::vector<KeyboardRecord> records_;
	std::mutex mutex_;

	std::thread check_thread_;
	bool exit_;
};

