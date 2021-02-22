
// MFC_RPGDlg.h: 헤더 파일
//

#pragma once


// CMFCRPGDlg 대화 상자
class CMFCRPGDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCRPGDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_RPG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editName;
	CComboBox m_comboClass;
	CEdit m_editHP;
	CEdit m_editMP;
	CEdit m_editStr;
	CEdit m_editInt;
	CEdit m_editDEF;
	CStatic m_staticBonus;

	CString m_cstrName;

	int m_nBonus = 0;
	int m_nHP = 0;
	int m_nMP = 0;
	int m_nStr = 0;
	int m_nInt = 0;
	int m_nDef = 0;

	afx_msg void OnCbnSelchangeComboClass();
	afx_msg void OnDeltaposSpinHp(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinHp2(NMHDR *pNMHDR, LRESULT *pResult);
};
