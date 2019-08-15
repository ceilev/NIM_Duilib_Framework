/** @file CircleProgress.h
* @brief Բ���͹������ؼ���Բ���м�������ı�����85%��
* @copyright (c) 2019-2022, NetEase Inc. All rights reserved
* @author Xuhuajie
* @date 2019/8/14
*/

#ifndef UI_CONTROL_CIRCLEPROGRESS_H_
#define UI_CONTROL_CIRCLEPROGRESS_H_

#pragma once

namespace ui
{

	class UILIB_API CircleProgress : public Progress
	{
	public:
		CircleProgress();

		/// ��д���෽�����ṩ���Ի����ܣ���ο���������
		virtual void SetAttribute(const std::wstring& strName, const std::wstring& strValue) override;
		virtual void PaintStatusImage(IRenderContext* pRender) override;
		virtual void ClearImageCache() override;

		/**
		* @brief ����Բ�ι�����
		* @param[in] bCircular Ϊ true ʱ����ΪԲ�ι�������false ʱ����Ϊ������������Ĭ��Ϊ true
		* @return ��
		*/
		void SetCircular(bool bCircular = true);
		/**
		* @brief ���õ�������
		* @param[in] bClockwise Ϊ true ʱ����Ϊ˳ʱ�룬false ʱ����Ϊ��ʱ�룬Ĭ��Ϊ true
		* @return ��
		*/
		void SetClockwiseRotation(bool bClockwise = true);
		/**
		* @brief ����Բ������
		* @param[in] nCircleWidth ������ֵ
		* @return ��
		*/
		void SetCircleWidth(int nCircleWidth);
		/**
		* @brief ���ý�����������ɫ
		* @param[in] strColorҪ���õı�����ɫ�ַ��������ַ��������� global.xml �д���
		* @return ��
		*/
		void SetBackgroudColor(const std::wstring& strColor);
		/**
		* @brief ���ý�����ǰ����ɫ
		* @param[in] strColorҪ���õ�ǰ����ɫ�ַ��������ַ��������� global.xml �д���
		* @return ��
		*/
		void SetForegroudColor(const std::wstring& strColor);
		/**
		* @brief ���ý�����ǰ��������ɫ����ForegroudColorͬʱʹ�ã����Բ�����,���޽���Ч��
		* @param[in] strColorҪ���õ�ǰ��������ɫ�ַ��������ַ��������� global.xml �д���
		* @return ��
		*/
		void SetCircleGradientColor(const std::wstring& strColor);
		/**
		* @brief ���ý���ָʾ�ƶ�ͼ��
		* @param[in] sIndicatorImageҪ���õ�ͼƬ
		* @return ��
		*/
		void SetIndicator(const std::wstring&  sIndicatorImage);
	
	protected:
		bool          m_bCircular;
		bool          m_bClockwise;
		int           m_nCircleWidth;
		DWORD         m_dwBackgroundColor;
		DWORD         m_dwForegroundColor;
		DWORD         m_dwGradientColor;
		//Image         m_IndicatorImage;   //ʹ��image�����޷�����������Ҫ���þ���任
		Gdiplus::Image*		m_pIndicator;   //����Ŀǰά����Դ����
		std::wstring  m_sIndicatorImage;

	};

} // namespace ui

#endif // UI_CONTROL_CIRCLEPROGRESS_H_