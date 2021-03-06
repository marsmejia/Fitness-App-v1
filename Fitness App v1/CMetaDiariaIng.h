#pragma once


// CMetaDiariaIng dialog

class CMetaDiariaIng : public CDialogEx
{
	DECLARE_DYNAMIC(CMetaDiariaIng)

public:
	CMetaDiariaIng(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMetaDiariaIng();
	BOOL OnInitDialog();
	friend class CFitnessAppv1Dlg;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_METADIARIA_I };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	int m_pasos;
	int m_horas_p;
	int m_min_p;
	int m_seg_p;
	CComboBox m_ComboBoxCtrl2;
	CString m_StrTextCtrl2;
	double m_cal;
	int m_horas_a;
	int m_min_a;
	int m_seg_a;
	CPersona usuario;
public:
	afx_msg void OnBnClickedBtnGuardar();
	bool modificacion;
};
