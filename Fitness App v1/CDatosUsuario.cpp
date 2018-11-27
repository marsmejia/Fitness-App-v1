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
	UpdateData(false);
}

void CDatosUsuario::destruir()
{
	DestroyWindow();
}

BOOL CDatosUsuario::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_usernum_s.Format(_T("Usuario : %d"), m_usernum);
	UpdateData(false);
	CButton *pButton, *pButton2, *pButton3;
	if (usuario.m_sexo == 'm') {
		pButton = (CButton *)GetDlgItem(IDC_RAD_SEXO_M);
		pButton->SetCheck(true);
	}
	else {
		pButton = (CButton *)GetDlgItem(IDC_RAD_SEXO_F);
		pButton->SetCheck(true);
	}
	switch (usuario.m_condicion) {
	case 1:
		pButton2 = (CButton *)GetDlgItem(IDC_RAD_CON1);
		pButton2->SetCheck(true);
		break;
	case 2:
		pButton2 = (CButton *)GetDlgItem(IDC_RAD_CON2);
		pButton2->SetCheck(true);
		break;
	case 3:
		pButton2 = (CButton *)GetDlgItem(IDC_RAD_CON3);
		pButton2->SetCheck(true);
		break;
	case 4:
		pButton2 = (CButton *)GetDlgItem(IDC_RAD_CON4);
		pButton2->SetCheck(true);
		break;
	default:
		pButton2 = (CButton *)GetDlgItem(IDC_RAD_CON0);
		pButton2->SetCheck(true);
		break;
	}
	switch (usuario.m_proposito) {
	case 1:
		pButton3 = (CButton *)GetDlgItem(IDC_RAD_PROP1);
		pButton3->SetCheck(true);
		break;
	case 2:
		pButton3 = (CButton *)GetDlgItem(IDC_RAD_PROP2);
		pButton3->SetCheck(true);
		break;
	case 3:
		pButton3 = (CButton *)GetDlgItem(IDC_RAD_PROP3);
		pButton3->SetCheck(true);
		break;
	default:
		pButton3 = (CButton *)GetDlgItem(IDC_RAD_PROP4);
		pButton3->SetCheck(true);
		break;
	}
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
}


BEGIN_MESSAGE_MAP(CDatosUsuario, CDialogEx)
END_MESSAGE_MAP()


// CDatosUsuario message handlers
