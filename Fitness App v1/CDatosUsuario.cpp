// CDatosUsuario.cpp : implementation file
//

#include "stdafx.h"
#include "Fitness App v1.h"
#include "CDatosUsuario.h"
#include "afxdialogex.h"


// CDatosUsuario dialog

IMPLEMENT_DYNAMIC(CDatosUsuario, CDialogEx)

CDatosUsuario::CDatosUsuario(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DATOSUSER, pParent)
	, m_usernum_s(_T(""))
	, m_nombre(_T(""))
	, m_edad(0)
	, m_estatura(0)
	, m_peso(0)
	, m_imc(0)
	, m_imc_rango(_T(""))
	, m_ctrl_sexo(-1)
	, m_condicion(_T(""))
	, m_proposito(_T(""))
{

}

CDatosUsuario::~CDatosUsuario()
{
}

void CDatosUsuario::cargarDatos(int usernum)
{
	m_usernum = usernum;
	m_usernum_s.Format(_T("Usuario : %d"), m_usernum);
	m_nombre = usuario.m_nombre;
	m_edad = usuario.m_edad;
	m_estatura = usuario.m_estatura;
	m_peso = usuario.m_peso;
	m_imc = usuario.obtenerIMC();
	m_imc_rango = usuario.riesgoImc();
	
	if (usuario.m_sexo == 'm') {
		m_ctrl_sexo = 0;
	}
	else {
		m_ctrl_sexo = 1;
	}
	switch (usuario.m_condicion) {
	case 1:
		m_condicion = "Diabetes";
		break;
	case 2:
		m_condicion = "Hipertension";
		break;
	case 3:
		m_condicion = "Artritis";
		break;
	case 4:
		m_condicion = "Embarazo";
		break;
	default:
		m_condicion = "Ninguna";
		break;
	}
	switch (usuario.m_proposito) {
	case 1:
		m_proposito = "Bajar de Peso";
		break;
	case 2:
		m_proposito = "Elevar Rendimiento";
		break;
	case 3:
		m_proposito = "Mantenimiento";
		break;
	default:
		m_proposito = "Prescripcion Medica";
		break;
	}
	UpdateData(false);
}



BOOL CDatosUsuario::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_usernum_s.Format(_T("Usuario : %d"), m_usernum);
	m_nombre = "Sin Usuarios!";
	m_imc = 0;
	m_imc_rango = "";
	UpdateData(false);
	return true;
}


void CDatosUsuario::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_USERNUM, m_usernum_s);
	DDX_Text(pDX, IDC_EDT_USERNAME, m_nombre);
	DDX_Text(pDX, IDC_EDT_EDAD, m_edad);
	DDX_Text(pDX, IDC_EDT_ESTATURA, m_estatura);
	DDX_Text(pDX, IDC_EDT_PESO, m_peso);
	DDX_Text(pDX, IDC_EDIT1, m_imc);
	DDX_Text(pDX, IDC_EDT_EDAD2, m_imc_rango);
	DDX_Radio(pDX, IDC_RAD_SEXO_M, m_ctrl_sexo);
	DDX_Text(pDX, IDC_EDIT3, m_condicion);
	DDX_Text(pDX, IDC_EDIT2, m_proposito);
}


BEGIN_MESSAGE_MAP(CDatosUsuario, CDialogEx)
END_MESSAGE_MAP()


// CDatosUsuario message handlers
