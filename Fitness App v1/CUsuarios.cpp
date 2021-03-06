// CUsuarios.cpp : implementation file
//

#include "stdafx.h"
#include "Fitness App v1.h"
#include "CUsuarios.h"
#include "afxdialogex.h"


// CUsuarios dialog

IMPLEMENT_DYNAMIC(CUsuarios, CDialogEx)

CUsuarios::CUsuarios(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USUARIOS, pParent)
	, m_nombre(_T(""))
	, m_edad(0)
	, m_estatura(0)
	, m_peso(0)
	, m_usernum_s(_T(""))
	, m_ctrl_sexo(-1)
	, m_ctrl_cond(-1)
	, m_ctrl_prop(-1)
{

}

CUsuarios::~CUsuarios()
{
}

void CUsuarios::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_USERNAME, m_nombre);
	DDX_Text(pDX, IDC_EDT_EDAD, m_edad);
	DDX_Text(pDX, IDC_EDT_ESTATURA, m_estatura);
	DDX_Text(pDX, IDC_EDT_PESO, m_peso);
	DDX_Text(pDX, IDC_EDT_USERNUM, m_usernum_s);
	DDX_Radio(pDX, IDC_RAD_SEXO_M, m_ctrl_sexo);
	DDX_Radio(pDX, IDC_RAD_CON0, m_ctrl_cond);
	DDX_Radio(pDX, IDC_RAD_PROP1, m_ctrl_prop);
	DDX_Control(pDX, IDC_RAD_CON4, m_embarazo);
}


BEGIN_MESSAGE_MAP(CUsuarios, CDialogEx)
	ON_BN_CLICKED(ID_GUARDAR, &CUsuarios::OnBnClickedGuardar)
	ON_BN_CLICKED(IDCANCEL, &CUsuarios::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_RAD_SEXO_F, &CUsuarios::OnBnClickedRadSexoF)
	ON_BN_CLICKED(IDC_RAD_SEXO_M, &CUsuarios::OnBnClickedRadSexoM)
END_MESSAGE_MAP()


// CUsuarios message handlers


void CUsuarios::OnBnClickedGuardar()
{
	UpdateData(true);
	char temp[50];
	CStringA tempString;
	tempString = m_nombre;
	strcpy_s(temp, tempString.GetString());
	usuario.asignarNombre(temp);
	usuario.m_edad = m_edad;
	usuario.m_estatura = m_estatura;
	usuario.m_peso = m_peso;
	if (m_ctrl_sexo == 0) {
		usuario.m_sexo = 'm';
	}
	else {
		usuario.m_sexo = 'f';
	}
	switch (m_ctrl_cond) {
	case 0:
		usuario.m_condicion = 0;
		break;
	case 1:
		usuario.m_condicion = 1;
		break;
	case 2:
		usuario.m_condicion = 2;
		break;
	case 3:
		usuario.m_condicion = 3;
		break;
	case 4:
		usuario.m_condicion = 4;
		break;
	}
	switch (m_ctrl_prop) {
	case 0:
		usuario.m_proposito = 1;
		break;
	case 1:
		usuario.m_proposito = 2;
		break;
	case 2:
		usuario.m_proposito = 3;
		break;
	case 3:
		usuario.m_proposito = 4;
		break;
	}
	cancelar = false;
	CDialogEx::OnOK();
	// TODO: Add your control notification handler code here
}

void CUsuarios::asignarCaso(int caso, int usernum)
{
	m_caso = caso;
	m_usernum = usernum;
	m_usernum_s.Format(_T("Usuario : %d"), usernum);
	if (m_caso == 2) {
		m_nombre = usuario.m_nombre;
		m_edad = usuario.m_edad;
		m_estatura = usuario.m_estatura;
		m_peso = usuario.m_peso;
		if (usuario.m_sexo == 'm') {
			m_ctrl_sexo = 0;
		}
		else {
			m_ctrl_sexo = 1;
		}
		switch (usuario.m_condicion) {
		case 1:
			m_ctrl_cond = 1;
			break;
		case 2:
			m_ctrl_cond = 2;
			break;
		case 3:
			m_ctrl_cond = 3;
			break;
		case 4:
			m_ctrl_cond = 4;
			break;
		default:
			m_ctrl_cond = 0;
			break;
		}
		switch (usuario.m_proposito) {
		case 1:
			m_ctrl_prop = 0;
			break;
		case 2:
			m_ctrl_prop = 1;
			break;
		case 3:
			m_ctrl_prop = 2;
			break;
		default:
			m_ctrl_prop = 3;
			break;
		}
	}
	else {
		m_nombre = "";
		m_edad = 0;
		m_estatura = 0.0;
		m_peso = 0.0;
		m_ctrl_cond = -1;
		m_ctrl_prop = -1;
		m_ctrl_sexo = -1;
	}
	//UpdateData(false);
}

void CUsuarios::OnBnClickedCancel()
{
	cancelar = true;
	CDialogEx::OnCancel();
}

void CUsuarios::OnBnClickedRadSexoF()
{
	m_embarazo.ShowWindow(SW_SHOW);
}

BOOL CUsuarios::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_embarazo.ShowWindow(SW_HIDE);
	return TRUE;
}


void CUsuarios::OnBnClickedRadSexoM()
{
	m_embarazo.ShowWindow(SW_HIDE);
}
