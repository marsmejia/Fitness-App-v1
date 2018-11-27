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
	ON_BN_CLICKED(IDCANCEL, &CUsuarios::OnBnClickedCancel)
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
	cancelar = false;
	CDialogEx::OnOK();
	// TODO: Add your control notification handler code here
}

void CUsuarios::asignarCaso(int caso, int usernum)
{
	m_caso = caso;
	m_usernum.Format(_T("Usuario : %d"), usernum);
}

void CUsuarios::OnBnClickedCancel()
{
	cancelar = true;
	CDialogEx::OnCancel();
}

BOOL CUsuarios::OnInitDialog()
{ 
	if (m_caso == 2) {
		m_nombre = usuario.m_nombre;
		m_edad = usuario.m_edad;
		m_estatura = usuario.m_estatura;
		m_peso = usuario.m_peso;
		CButton *pButton, *pButton2, *pButton3;
		if(usuario.m_sexo == 'm') {
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
		//UpdateData(false);
	}
	else {
		m_nombre = _T("");
		m_edad = 0;
		m_estatura = 0.0;
		m_peso = 0.0;
		//UpdateData(false);
	}
	return true;
}
