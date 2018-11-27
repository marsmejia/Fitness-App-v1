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
	, m_usernum(_T(""))
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
	DDX_Text(pDX, IDC_EDT_USERNUM, m_usernum);
}


BEGIN_MESSAGE_MAP(CUsuarios, CDialogEx)
	ON_BN_CLICKED(ID_GUARDAR, &CUsuarios::OnBnClickedGuardar)
END_MESSAGE_MAP()


// CUsuarios message handlers


void CUsuarios::OnBnClickedGuardar()
{
	UpdateData(true);
	usuario.m_nombre = temp;
	usuario.m_edad = m_edad;
	usuario.m_estatura = m_estatura;
	usuario.m_peso = m_peso;
	int selec;
	selec = GetCheckedRadioButton(IDC_RAD_SEXO_M, IDC_RAD_SEXO_F);
	if (selec == IDC_RAD_SEXO_M) {
		usuario.m_sexo = 'm';
	}
	else {
		usuario.m_sexo = 'f';
	}

	selec = GetCheckedRadioButton(IDC_RAD_CON0, IDC_RAD_CON4);
	switch (selec) {
	case IDC_RAD_CON0:
		usuario.m_condicion = 0;
		break;
	case IDC_RAD_CON1:
		usuario.m_condicion = 1;
		break;
	case IDC_RAD_CON2:
		usuario.m_condicion = 2;
		break;
	case IDC_RAD_CON3:
		usuario.m_condicion = 3;
		break;
	case IDC_RAD_CON4:
		usuario.m_condicion = 4;
		break;
	}

	selec = GetCheckedRadioButton(IDC_RAD_PROP1, IDC_RAD_PROP4);
	switch (selec) {
	case IDC_RAD_PROP1:
		usuario.m_proposito = 1;
		break;
	case IDC_RAD_PROP2:
		usuario.m_proposito = 2;
		break;
	case IDC_RAD_PROP3:
		usuario.m_proposito = 3;
		break;
	case IDC_RAD_PROP4:
		usuario.m_proposito = 4;
		break;
	}
	CDialogEx::OnCancel();
	// TODO: Add your control notification handler code here
}

void CUsuarios::asignarCaso(int caso, int usernum)
{
	m_caso = caso;
	m_usernum.Format(_T("Usuario : %d"), usernum);
	if (caso == 2){
		m_nombre = usuario.m_nombre;
		m_edad = usuario.m_edad;
		m_estatura = usuario.m_estatura;
		m_peso = usuario.m_peso;
		if(usuario.m_sexo == 'm') {
			CheckRadioButton(IDC_RAD_SEXO_M, IDC_RAD_SEXO_F, IDC_RAD_SEXO_M);
		}
		else {
			CheckRadioButton(IDC_RAD_SEXO_M, IDC_RAD_SEXO_F, IDC_RAD_SEXO_F);
		}
		switch (usuario.m_condicion) {
		case 1:
			CheckRadioButton(IDC_RAD_CON0, IDC_RAD_CON4, IDC_RAD_CON1);
			break;
		case 2:
			CheckRadioButton(IDC_RAD_CON0, IDC_RAD_CON4, IDC_RAD_CON2);
			break;
		case 3:
			CheckRadioButton(IDC_RAD_CON0, IDC_RAD_CON4, IDC_RAD_CON3);
			break;
		case 4:
			CheckRadioButton(IDC_RAD_CON0, IDC_RAD_CON4, IDC_RAD_CON4);
			break;
		default:
			CheckRadioButton(IDC_RAD_CON0, IDC_RAD_CON4, IDC_RAD_CON0);
			break;
		}
		switch (usuario.m_proposito) {
		case 1:
			CheckRadioButton(IDC_RAD_PROP1, IDC_RAD_PROP4, IDC_RAD_PROP1);
			break;
		case 2:
			CheckRadioButton(IDC_RAD_PROP1, IDC_RAD_PROP4, IDC_RAD_PROP2);
			break;
		case 3:
			CheckRadioButton(IDC_RAD_PROP1, IDC_RAD_PROP4, IDC_RAD_PROP3);
			break;
		default:
			CheckRadioButton(IDC_RAD_PROP1, IDC_RAD_PROP4, IDC_RAD_PROP4);
			break;
		}
		UpdateData(false);
	}
}
