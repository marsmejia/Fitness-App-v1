#pragma once


// CDesarollo dialog

class CDesarollo : public CDialogEx
{
	DECLARE_DYNAMIC(CDesarollo)

public:
	CDesarollo(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDesarollo();
	friend class CFitnessAppv1Dlg;
	BOOL OnInitDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CPersona usuario;
	DECLARE_MESSAGE_MAP()
private:
	int m_pasos;
	int m_horas_p;
	int m_min_p;
	int m_seg_p;
	int m_horas_a;
	int m_min_a;
	int m_seg_a;
	double m_cal;
public:
	afx_msg void OnBnClickedOk();
private:
	CComboBox m_ComboBoxCtrl;
	CString m_StrTextCtrl;
};
