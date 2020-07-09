#pragma once

enum ThreadId { kThreadUI, kThreadGlobalMisc };


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
  void StartDownloadTask(const std::string &url);
	void Upgrade(const std::wstring &old_exe, const std::wstring &new_exe);
	std::wstring CreateTempFile();
	void OnDownloadComplete();
	std::wstring GetArgv();

  ui::Progress* progress_bar_;
	ui::Label* label_progress_;
	ui::Label* label_title_;

	std::ofstream* tmp_fstream_;
	std::wstring tmp_file_name_;

};

