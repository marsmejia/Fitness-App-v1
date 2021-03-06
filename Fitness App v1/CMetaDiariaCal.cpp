// CMetaDiariaCal.cpp : implementation file
//

#include "stdafx.h"
#include "Fitness App v1.h"
#include "CMetaDiariaCal.h"
#include "afxdialogex.h"


// CMetaDiariaCal dialog

IMPLEMENT_DYNAMIC(CMetaDiariaCal, CDialogEx)

CMetaDiariaCal::CMetaDiariaCal(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_METADIARIA_C, pParent)
	, m_proposito(_T(""))
	, m_condicion(_T(""))
	, m_pasos(0)
	, m_horas_p(0)
	, m_min_p(0)
	, m_seg_p(0)
	, m_act(_T(""))
	, m_cal(0)
	, m_horas_a(0)
	, m_min_a(0)
	, m_seg_a(0)
{

}

CMetaDiariaCal::~CMetaDiariaCal()
{
}

void CMetaDiariaCal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_proposito);
	DDX_Text(pDX, IDC_EDIT2, m_condicion);
	DDX_Text(pDX, IDC_EDIT3, m_pasos);
	DDX_Text(pDX, IDC_EDIT13, m_horas_p);
	DDX_Text(pDX, IDC_EDIT15, m_min_p);
	DDX_Text(pDX, IDC_EDIT5, m_seg_p);
	DDX_Text(pDX, IDC_EDIT11, m_act);
	DDX_Text(pDX, IDC_EDIT10, m_cal);
	DDX_Text(pDX, IDC_EDIT6, m_horas_a);
	DDX_Text(pDX, IDC_EDIT16, m_min_a);
	DDX_Text(pDX, IDC_EDIT9, m_seg_a);
	DDX_Control(pDX, IDC_EDIT2, m_cntrl_cond);
}


BEGIN_MESSAGE_MAP(CMetaDiariaCal, CDialogEx)
END_MESSAGE_MAP()


// CMetaDiariaCal message handlers

void CMetaDiariaCal::calcular()
{
	int actividadprom;
	switch (usuario.obtenerProposito()) {
	default:
		switch (usuario.obtenerCondicion()) {
		case 0:
			actividadprom = usuario.obtenerActividadProm();
			m_horas_a = usuario.duracionActividadFisica2.obtenerHoras();
			m_min_a = usuario.duracionActividadFisica2.obtenerMinutos();
			m_seg_a = usuario.duracionActividadFisica2.obtenerSegundos();
			usuario.duracionActividadFisica.asignarTodo(m_horas_a, m_min_a, m_seg_a);
			m_pasos = usuario.m_pasos;
			m_horas_p = usuario.duracionActividadPasos2.obtenerHoras();
			m_min_p = usuario.duracionActividadPasos2.obtenerMinutos();
			m_seg_p = usuario.duracionActividadPasos2.obtenerSegundos();
			usuario.duracionActividadPasos.asignarTodo(m_horas_p, m_min_p, m_seg_p);
			break;
		case 1:
			actividadprom = 2;
			usuario.asignarActividad(2);
			m_horas_a = 0;
			m_min_a = 30;
			m_seg_a = 0;
			usuario.duracionActividadFisica.asignarTodo(0, 20, 0);
			m_pasos = 2000;
			usuario.m_metaPasos = m_pasos;
			m_horas_p = 1;
			m_min_p = 0;
			m_seg_p = 0;
			usuario.duracionActividadPasos.asignarTodo(1, 0, 0);
		case 2:
			actividadprom = 2;
			usuario.asignarActividad(2);
			m_horas_a = 1;
			m_min_a = 15;
			m_seg_a = 0;
			usuario.duracionActividadFisica.asignarTodo(1, 15, 0);
			m_pasos = 3000;
			usuario.m_metaPasos = m_pasos;
			m_horas_p = 2;
			m_min_p = 0;
			m_seg_p = 0;
			usuario.duracionActividadPasos.asignarTodo(2, 0, 0);
			break;
		case 3:
			actividadprom = 1;
			usuario.asignarActividad(1);
			m_horas_a = 0;
			m_min_a = 30;
			m_seg_a = 0;
			usuario.duracionActividadFisica.asignarTodo(0, 30, 0);
			m_pasos = 5000;
			usuario.m_metaPasos = m_pasos;
			m_horas_p = 6;
			m_min_p = 0;
			m_seg_p = 0;
			usuario.duracionActividadPasos.asignarTodo(6, 0, 0);
			break;
		case 4:
			actividadprom = 1;
			usuario.asignarActividad(1);
			m_horas_a = 0;
			m_min_a = 15;
			m_seg_a = 0;
			usuario.duracionActividadFisica.asignarTodo(0, 15, 0);
			m_pasos = 3500;
			usuario.m_metaPasos = m_pasos;
			m_horas_p = 8;
			m_min_p = 0;
			m_seg_p = 0;
			usuario.duracionActividadPasos.asignarTodo(8, 0, 0);
			break;
		}
		break;
	case 1:
		switch (usuario.obtenerCondicion()) {
		case 0:
			if (usuario.m_actividad < 3) {
				actividadprom = (usuario.m_activdadprom + 1);
			}
			else {
				actividadprom = usuario.m_activdadprom;
			}
			usuario.asignarActividad(actividadprom);
			usuario.duracionActividadFisica.asignarMinTotales(usuario.duracionActividadFisica2.obtenerMinTotales() + 15);
			m_horas_a = usuario.duracionActividadFisica2.obtenerHoras();
			m_min_a = usuario.duracionActividadFisica2.obtenerMinutos();
			m_seg_a = usuario.duracionActividadFisica2.obtenerSegundos();
			m_pasos = usuario.m_pasos + 1000;
			usuario.m_metaPasos = m_pasos;
			m_horas_p = usuario.duracionActividadPasos2.obtenerHoras();
			m_min_p = usuario.duracionActividadPasos2.obtenerMinutos();
			m_seg_p = usuario.duracionActividadPasos2.obtenerSegundos();
			usuario.duracionActividadPasos.asignarTodo(m_horas_p, m_min_p, m_seg_p);
			break;
		case 1:
			actividadprom = 2;
			usuario.asignarActividad(2);
			m_horas_a = 0;
			m_min_a = 30;
			m_seg_a = 0;
			usuario.duracionActividadFisica.asignarTodo(0, 30, 0);
			m_pasos = 3000;
			usuario.m_metaPasos = m_pasos;
			m_horas_p = 1;
			m_min_p = 0;
			m_seg_p = 0;
			usuario.duracionActividadPasos.asignarTodo(1, 0, 0);
			break;
		case 2:
			actividadprom = 2;
			usuario.asignarActividad(2);
			m_horas_a = 1;
			m_min_a = 0;
			m_seg_a = 0;
			usuario.duracionActividadFisica.asignarTodo(1, 0, 0);
			m_pasos = 4000;
			usuario.m_metaPasos = m_pasos;
			m_horas_p = 2;
			m_min_p = 0;
			m_seg_p = 0;
			usuario.duracionActividadPasos.asignarTodo(2, 0, 0);
			break;
		case 3:
			actividadprom = 1;
			usuario.asignarActividad(1);
			m_horas_a = 0;
			m_min_a = 30;
			m_seg_a = 0;
			usuario.duracionActividadFisica.asignarTodo(0, 30, 0);
			m_pasos = 6000;
			usuario.m_metaPasos = m_pasos;
			m_horas_p = 6;
			m_min_p = 0;
			m_seg_p = 0;
			usuario.duracionActividadPasos.asignarTodo(6, 0, 0);
			break;
		case 4:
			actividadprom = 1;
			usuario.asignarActividad(1);
			m_horas_a = 0;
			m_min_a = 25;
			m_seg_a = 0;
			usuario.duracionActividadFisica.asignarTodo(0, 25, 0);
			m_pasos = 5000;
			usuario.m_metaPasos = m_pasos;
			m_horas_p = 8;
			m_min_p = 0;
			m_seg_p = 0;
			usuario.duracionActividadPasos.asignarTodo(8, 0, 0);
			break;
		}
		break;
	case 2:
		switch (usuario.obtenerCondicion()) {
		case 0:

			if (usuario.m_actividad < 4) {
				actividadprom = (usuario.m_activdadprom + 1);
			}
			else {
				actividadprom = usuario.m_activdadprom;
			}
			usuario.asignarActividad(actividadprom);
			usuario.duracionActividadFisica.asignarMinTotales(usuario.duracionActividadFisica2.obtenerMinTotales() + 20);
			m_horas_a = usuario.duracionActividadFisica2.obtenerHoras();
			m_min_a = usuario.duracionActividadFisica2.obtenerMinutos();
			m_seg_a = usuario.duracionActividadFisica2.obtenerSegundos();
			m_pasos = usuario.m_pasos + 2000;
			usuario.m_metaPasos = m_pasos;
			m_horas_a = usuario.duracionActividadPasos2.obtenerHoras();
			m_min_a = usuario.duracionActividadPasos2.obtenerMinutos();
			m_seg_a = usuario.duracionActividadPasos2.obtenerSegundos();
			usuario.duracionActividadPasos.asignarTodo(m_horas_p, m_min_p, m_seg_p);
			break;
		case 1:
			actividadprom = 2;
			usuario.asignarActividad(2);
			m_horas_a = 0;
			m_min_a = 30;
			m_seg_a = 0;
			usuario.duracionActividadFisica.asignarTodo(0, 30, 0);
			m_pasos = 3000;
			usuario.m_metaPasos = m_pasos;
			m_horas_a = 1;
			m_min_a = 0;
			m_seg_a = 0;
			usuario.duracionActividadPasos.asignarTodo(1, 0, 0);
			break;
		case 2:
			actividadprom = 2;
			usuario.asignarActividad(2);
			m_horas_a = 1;
			m_min_a = 0;
			m_seg_a = 0;
			usuario.duracionActividadFisica.asignarTodo(1, 0, 0);
			m_pasos = 4000;
			usuario.m_metaPasos = m_pasos;
			m_horas_a = 2;
			m_min_a = 0;
			m_seg_a = 0;
			usuario.duracionActividadPasos.asignarTodo(2, 0, 0);
			break;
		case 3:
			actividadprom = 1;
			usuario.asignarActividad(1);
			m_horas_a = 0;
			m_min_a = 30;
			m_seg_a = 0;
			usuario.duracionActividadFisica.asignarTodo(0, 30, 0);
			m_pasos = 6000;
			usuario.m_metaPasos = m_pasos;
			m_horas_a = 6;
			m_min_a = 0;
			m_seg_a = 0;
			usuario.duracionActividadPasos.asignarTodo(6, 0, 0);
			break;
		case 4:
			actividadprom = 1;
			usuario.asignarActividad(1);
			m_horas_a = 0;
			m_min_a = 25;
			m_seg_a = 0;
			usuario.duracionActividadFisica.asignarTodo(0, 25, 0);
			m_pasos = 5000;
			usuario.m_metaPasos = m_pasos;
			m_horas_a = 8;
			m_min_a = 0;
			m_seg_a = 0;
			usuario.duracionActividadPasos.asignarTodo(8, 0, 0);
			break;
		}
		break;
	}
	m_cal = usuario.m_caloriasRecom;
	switch (actividadprom) {
	case 1:
		m_act = "Actividad Ligera";
		break;
	case 2:
		m_act = "Actividad Moderada";
		break;
	case 3:
		m_act = "Actividad Intensa";
		break;
	case 4:
		m_act = "Actividad Extremadamente Alta";
		break;
	}
	switch (usuario.m_condicion) {
	case 1:
		m_condicion = "y tu diabetes.";
		m_cntrl_cond.ShowWindow(SW_SHOW);
		break;
	case 2:
		m_condicion = "y tu hipertension.";
		m_cntrl_cond.ShowWindow(SW_SHOW);
		break;
	case 3:
		m_condicion = "y tu artritis";
		m_cntrl_cond.ShowWindow(SW_SHOW);
		break;
	case 4:
		m_act = "y tu embarazo";
		m_cntrl_cond.ShowWindow(SW_SHOW);
		break;
	}

	// 1 - Bajar de Peso 2 - Elevar Rendimiento 3 - Mantenimineto 4 - Prescripcion Medica
	switch (usuario.m_proposito) {
	case 1:
		m_proposito = "bajar de peso";
		break;
	case 2:
		m_proposito = "elevar rendimiento";
		break;
	case 3:
		m_proposito = "mantenimineto";
		break;
	case 4:
		m_proposito = "prescripcion medica";
		break;
	}
	modificacion = true;
	UpdateData(false);
}

BOOL CMetaDiariaCal::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_cntrl_cond.ShowWindow(SW_HIDE);
	return TRUE;
}
