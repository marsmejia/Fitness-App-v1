// CMetaDiariaIng.cpp : implementation file
//

#include "stdafx.h"
#include "Fitness App v1.h"
#include "CMetaDiariaIng.h"
#include "afxdialogex.h"


// CMetaDiariaIng dialog

IMPLEMENT_DYNAMIC(CMetaDiariaIng, CDialogEx)

CMetaDiariaIng::CMetaDiariaIng(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_METADIARIA_I, pParent)
	, m_pasos(0)
	, m_horas_p(0)
	, m_min_p(0)
	, m_seg_p(0)
	, m_StrTextCtrl2(_T(""))
	, m_cal(0)
	, m_horas_a(0)
	, m_min_a(0)
	, m_seg_a(0)
{

}

CMetaDiariaIng::~CMetaDiariaIng()
{
}

BOOL CMetaDiariaIng::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString str;
	str = "Ninguna";
	m_ComboBoxCtrl2.AddString(str);
	str = "Actividad Ligera";
	m_ComboBoxCtrl2.AddString(str);
	str = "Actividad Moderada";
	m_ComboBoxCtrl2.AddString(str);
	str = "Actividad Intensa";
	m_ComboBoxCtrl2.AddString(str);
	str = "Actividad Extremadamente Alta";
	m_ComboBoxCtrl2.AddString(str);
	m_ComboBoxCtrl2.SetCurSel(0);
	return TRUE;
}
void CMetaDiariaIng::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_pasos);
	DDX_Text(pDX, IDC_EDIT1, m_horas_p);
	DDX_Text(pDX, IDC_EDIT13, m_min_p);
	DDX_Text(pDX, IDC_EDIT3, m_seg_p);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBoxCtrl2);
	DDX_CBString(pDX, IDC_COMBO1, m_StrTextCtrl2);
	DDX_Text(pDX, IDC_EDIT8, m_cal);
	DDX_Text(pDX, IDC_EDIT4, m_horas_a);
	DDX_Text(pDX, IDC_EDIT14, m_min_a);
	DDX_Text(pDX, IDC_EDIT6, m_seg_a);
}


BEGIN_MESSAGE_MAP(CMetaDiariaIng, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_GUARDAR, &CMetaDiariaIng::OnBnClickedBtnGuardar)
END_MESSAGE_MAP()


// CMetaDiariaIng message handlers


void CMetaDiariaIng::OnBnClickedBtnGuardar()
{
	UpdateData(true);
	int act;
	if (m_StrTextCtrl2 == "Actividad Ligera") {
		act = 1;
	}
	else if (m_StrTextCtrl2 == "Actividad Moderada") {
		act = 2;
	}
	else if (m_StrTextCtrl2 == "Actividad Intensa") {
		act = 3;
	}
	else if (m_StrTextCtrl2 == "Actividad Extremadamente Alta") {
		act = 4;
	}
	else {
		act = 5;
	}
	usuario.asignarActividad(act);
	usuario.asignarDuracionAF(m_horas_a, m_min_a, m_seg_a);
	usuario.asignarCaloriasRecom(m_cal);
	usuario.asignarPasosMeta(m_pasos);
	usuario.asignarDuracionP(m_horas_p, m_min_p, m_seg_p);
	UpdateData(false);
	modificacion = true;
	// TODO: Add your control notification handler code here
}
