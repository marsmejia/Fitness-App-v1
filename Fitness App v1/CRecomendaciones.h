#pragma once


// CRecomendaciones dialog

class CRecomendaciones : public CDialogEx
{
	DECLARE_DYNAMIC(CRecomendaciones)

public:
	CRecomendaciones(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CRecomendaciones();
	void asignarVariables(char*, double, double, double, double, double, double, double, double, double, double);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RECOMENDACIONES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CString m_titulo;
	double m_cal;
	double m_cal_resta;
	double m_carbo;
	double m_gt;
	double m_gs;
	double m_gpi;
	double m_gmi;
	double m_gtrans;
	double m_fibra;
	double m_col;
};
