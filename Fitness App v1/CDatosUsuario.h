#pragma once


// CDatosUsuario dialog

class CDatosUsuario : public CDialogEx
{
	DECLARE_DYNAMIC(CDatosUsuario)

public:
	CDatosUsuario(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDatosUsuario();
	void cargarDatos(int);
	BOOL OnInitDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATOSUSER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CString m_usernum_s;
	CString m_nombre;
	int m_edad;
	double m_estatura;
	double m_peso;
	double m_imc;
	CString m_imc_rango;
	CPersona usuario;
	int m_usernum;
	friend class CFitnessAppv1Dlg;
	int m_ctrl_sexo;
	CString m_condicion;
	CString m_proposito;
};
