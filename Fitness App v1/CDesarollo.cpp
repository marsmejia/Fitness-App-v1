// CDesarollo.cpp : implementation file
//

#include "stdafx.h"
#include "Fitness App v1.h"
#include "CDesarollo.h"
#include "afxdialogex.h"


// CDesarollo dialog

IMPLEMENT_DYNAMIC(CDesarollo, CDialogEx)

CDesarollo::CDesarollo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_pasos(0)
	, m_horas_p(0)
	, m_min_p(0)
	, m_seg_p(0)
	, m_horas_a(0)
	, m_min_a(0)
	, m_seg_a(0)
	, m_cal(0)
	, m_StrTextCtrl(_T(""))
{

}

CDesarollo::~CDesarollo()
{
}

BOOL CDesarollo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString str;
	str = "Ninguna";
	m_ComboBoxCtrl.AddString(str);
	str = "Actividad Ligera";
	m_ComboBoxCtrl.AddString(str);
	str = "Actividad Moderada";
	m_ComboBoxCtrl.AddString(str);
	str = "Actividad Intensa";
	m_ComboBoxCtrl.AddString(str);
	str = "Actividad Extremadamente Alta";
	m_ComboBoxCtrl.AddString(str);
	m_ComboBoxCtrl.SetCurSel(0);
	return TRUE;
}

void CDesarollo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_pasos);
	DDX_Text(pDX, IDC_EDIT1, m_horas_p);
	DDX_Text(pDX, IDC_EDIT13, m_min_p);
	DDX_Text(pDX, IDC_EDIT3, m_seg_p);
	DDX_Text(pDX, IDC_EDIT4, m_horas_a);
	DDX_Text(pDX, IDC_EDIT14, m_min_a);
	DDX_Text(pDX, IDC_EDIT6, m_seg_a);
	DDX_Text(pDX, IDC_EDIT8, m_cal);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBoxCtrl);
	DDX_CBString(pDX, IDC_COMBO1, m_StrTextCtrl);
}


BEGIN_MESSAGE_MAP(CDesarollo, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDesarollo::OnBnClickedOk)
END_MESSAGE_MAP()


// CDesarollo message handlers


void CDesarollo::OnBnClickedOk()
{
	UpdateData(true);
	usuario.asignarPasos(m_pasos);
	usuario.asignarDuracionP2(m_horas_p, m_min_p, m_seg_p);
	usuario.asignarCalQuemadasPasos();
	int act;
	if (m_StrTextCtrl == "Actividad Ligera") {
		act = 1;
	}
	else if (m_StrTextCtrl == "Actividad Moderada") {
		act = 2;
	}
	else if (m_StrTextCtrl == "Actividad Intensa") {
		act = 3;
	}
	else if (m_StrTextCtrl == "Actividad Extremadamente Alta") {
		act = 4;
	}
	else {
		act = 5;
	}
	usuario.asignarDuracionAF2(m_horas_a, m_min_a, m_seg_a);
	usuario.asignarActividadProm(act);
	usuario.asignarCalQuemadasAF(act);
	usuario.asignarCaloriasIng(m_cal);
	usuario.calcularCalorias();
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
