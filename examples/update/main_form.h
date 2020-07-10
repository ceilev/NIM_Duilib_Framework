#pragma once

#include <map>

enum ThreadId { kThreadUI, kThreadGlobalMisc };

struct FileDescription {
  std::wstring url;
	std::wstring replace;
	std::wstring tmp;
};

struct UpdateDescription {
  std::wstring title;
  std::vector<FileDescription> files_desc;
	std::wstring launcher;
};

class MainForm : public ui::WindowImplBase
{
public:
	MainForm();
	~MainForm();

	/**
	 * ���������ӿ��Ǳ���Ҫ��д�Ľӿڣ����������������ӿ�����������
	 * GetSkinFolder		�ӿ�������Ҫ���ƵĴ���Ƥ����Դ·��
	 * GetSkinFile			�ӿ�������Ҫ���ƵĴ��ڵ� xml �����ļ�
	 * GetWindowClassName	�ӿ����ô���Ψһ��������
	 */
	virtual std::wstring GetSkinFolder() override;
	virtual std::wstring GetSkinFile() override;
	virtual std::wstring GetWindowClassName() const override;

	/**
	 * �յ� WM_CREATE ��Ϣʱ�ú����ᱻ���ã�ͨ����һЩ�ؼ���ʼ���Ĳ���
	 */
	virtual void InitWindow() override;

	/**
	 * �յ� WM_CLOSE ��Ϣʱ�ú����ᱻ����
	 */
	virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	/**
   * ��̬���½������ӿ�
   */
  void OnProgressValueChagned(float value);

	static const std::wstring kClassName;

private: 
  bool ParseCommandLine();
  void Download();
	std::wstring CreateTempFile();
	void OnDownloadComplete();
	std::wstring GetArgv();
	void SetInfo(const std::wstring &msg);

  ui::Progress* progress_bar_;
	ui::Label* label_info_;
	ui::Label* label_title_;

	UpdateDescription update_desc_;
	//std::ofstream* tmp_fs_;
	//std::wstring tmp_file_name_;

};

