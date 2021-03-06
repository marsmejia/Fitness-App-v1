#pragma once

// CUsuarios dialog

class CUsuarios : public CDialogEx
{
	DECLARE_DYNAMIC(CUsuarios)

public:
	CUsuarios(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUsuarios();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USUARIOS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CPersona usuario;
	DECLARE_MESSAGE_MAP()
private:
	CString m_nombre;
	int m_edad;
	double m_estatura;
	double m_peso;
	CString m_usernum_s;
	int m_caso, m_usernum;
	BOOL cancelar;
public:
	afx_msg void OnBnClickedGuardar();
	void asignarCaso(int,int);
	//CPersona ObtenerUsuario();
	friend class CFitnessAppv1Dlg;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedRadSexoF();
	BOOL OnInitDialog();
private:
	int m_ctrl_sexo;
	int m_ctrl_cond;
	int m_ctrl_prop;
	CButton m_embarazo;
public:
	afx_msg void OnBnClickedRadSexoM();
};
