// CProgreso.cpp : implementation file
//

#include "stdafx.h"
#include "Fitness App v1.h"
#include "CProgreso.h"
#include "afxdialogex.h"


// CProgreso dialog

IMPLEMENT_DYNAMIC(CProgreso, CDialogEx)

CProgreso::CProgreso(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROGRESO, pParent)
	, m_pasos_r(0)
	, m_horas_pr(0)
	, m_min_pr(0)
	, m_seg_pr(0)
	, m_act_r(_T(""))
	, m_cal_r(0)
	, m_horas_ar(0)
	, m_min_ar(0)
	, m_seg_ar(0)
	, m_pasos_m(0)
	, m_horas_pm(0)
	, m_min_pm(0)
	, m_seg_pm(0)
	, m_act_m(_T(""))
	, m_cal_m(0)
	, m_horas_am(0)
	, m_min_am(0)
	, m_seg_am(0)
{

}

CProgreso::~CProgreso()
{
}

void CProgreso::asignar(CPersona user)
{
	usuario = user;
	int temp;
	temp = usuario.obtenerActividadProm();
	switch (temp) {
	case 1:
		m_act_r = "Actividad Ligera";
		break;
	case 2:
		m_act_r = "Actividad Moderada";
		break;
	case 3:
		m_act_r = "Actividad Intensa";
		break;
	case 4:
		m_act_r = "Actividad Extremadamente Alta";
		break;
	case 5:
		m_act_r = "ANinguna";
		break;
	}
	m_pasos_r = usuario.obtenerPasos();
	m_horas_pr = usuario.duracionActividadPasos2.obtenerHoras();
	m_min_pr = usuario.duracionActividadPasos2.obtenerMinutos();
	m_seg_pr = usuario.duracionActividadPasos2.obtenerSegundos();
	m_cal_r = usuario.obtenerCaloriasIng();
	m_horas_ar = usuario.duracionActividadFisica2.obtenerHoras();
	m_min_ar = usuario.duracionActividadFisica2.obtenerMinutos();
	m_seg_ar = usuario.duracionActividadFisica2.obtenerSegundos();
	temp = usuario.obtenerActividad();
	switch (temp) {
	case 1:
		m_act_m = "Actividad Ligera";
		break;
	case 2:
		m_act_m = "Actividad Moderada";
		break;
	case 3:
		m_act_m = "Actividad Intensa";
		break;
	case 4:
		m_act_m = "Actividad Extremadamente Alta";
		break;
	case 5:
		m_act_m = "Ninguna";
		break;
	}
	m_pasos_m = usuario.obtenerPasosMeta();
	m_horas_pm = usuario.duracionActividadPasos.obtenerHoras();
	m_min_pm = usuario.duracionActividadPasos.obtenerMinutos();
	m_seg_pm = usuario.duracionActividadPasos.obtenerSegundos();
	m_cal_m = usuario.obtenerCaloriasRecom();
	m_horas_am = usuario.duracionActividadFisica.obtenerHoras();
	m_min_am = usuario.duracionActividadFisica.obtenerMinutos();
	m_seg_am = usuario.duracionActividadFisica.obtenerSegundos();
	UpdateData(false);
}

void CProgreso::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_pasos_r);
	DDX_Text(pDX, IDC_EDIT13, m_horas_pr);
	DDX_Text(pDX, IDC_EDIT15, m_min_pr);
	DDX_Text(pDX, IDC_EDIT5, m_seg_pr);
	DDX_Text(pDX, IDC_EDIT11, m_act_r);
	DDX_Text(pDX, IDC_EDIT10, m_cal_r);
	DDX_Text(pDX, IDC_EDIT6, m_horas_ar);
	DDX_Text(pDX, IDC_EDIT16, m_min_ar);
	DDX_Text(pDX, IDC_EDIT9, m_seg_ar);
	DDX_Text(pDX, IDC_EDIT12, m_pasos_m);
	DDX_Text(pDX, IDC_EDIT17, m_horas_pm);
	DDX_Text(pDX, IDC_EDIT18, m_min_pm);
	DDX_Text(pDX, IDC_EDIT19, m_seg_pm);
	DDX_Text(pDX, IDC_EDIT24, m_act_m);
	DDX_Text(pDX, IDC_EDIT23, m_cal_m);
	DDX_Text(pDX, IDC_EDIT20, m_horas_am);
	DDX_Text(pDX, IDC_EDIT21, m_min_am);
	DDX_Text(pDX, IDC_EDIT22, m_seg_am);
}


BEGIN_MESSAGE_MAP(CProgreso, CDialogEx)
END_MESSAGE_MAP()


// CProgreso message handlers


