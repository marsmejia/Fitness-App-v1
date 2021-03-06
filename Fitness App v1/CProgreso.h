#pragma once


// CProgreso dialog

class CProgreso : public CDialogEx
{
	DECLARE_DYNAMIC(CProgreso)

public:
	CProgreso(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CProgreso();
	void asignar(CPersona);
	friend class CFitnessAppv1Dlg;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRESO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CPersona usuario;
	int m_pasos_r;
	int m_horas_pr;
	int m_min_pr;
	int m_seg_pr;
	CString m_act_r;
	double m_cal_r;
	int m_horas_ar;
	int m_min_ar;
	int m_seg_ar;
	int m_pasos_m;
	int m_horas_pm;
	int m_min_pm;
	int m_seg_pm;
	CString m_act_m;
	double m_cal_m;
	int m_horas_am;
	int m_min_am;
	int m_seg_am;
};
