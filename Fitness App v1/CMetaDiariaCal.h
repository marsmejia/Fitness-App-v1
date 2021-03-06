#pragma once


// CMetaDiariaCal dialog

class CMetaDiariaCal : public CDialogEx
{
	DECLARE_DYNAMIC(CMetaDiariaCal)

public:
	CMetaDiariaCal(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMetaDiariaCal();
	friend class CFitnessAppv1Dlg;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_METADIARIA_C };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CString m_proposito;
	CString m_condicion;
	int m_pasos;
	int m_horas_p;
	int m_min_p;
	int m_seg_p;
	CString m_act;
	double m_cal;
	int m_horas_a;
	int m_min_a;
	int m_seg_a;
	CPersona usuario;
public:
	void calcular();
	bool modificacion;
	BOOL OnInitDialog();
private:
	CEdit m_cntrl_cond;
};
