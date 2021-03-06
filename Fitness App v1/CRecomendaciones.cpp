// CRecomendaciones.cpp : implementation file
//

#include "stdafx.h"
#include "Fitness App v1.h"
#include "CRecomendaciones.h"
#include "afxdialogex.h"


// CRecomendaciones dialog

IMPLEMENT_DYNAMIC(CRecomendaciones, CDialogEx)

CRecomendaciones::CRecomendaciones(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RECOMENDACIONES, pParent)
	, m_titulo(_T(""))
	, m_cal(0)
	, m_cal_resta(0)
	, m_carbo(0)
	, m_gt(0)
	, m_gs(0)
	, m_gpi(0)
	, m_gmi(0)
	, m_gtrans(0)
	, m_fibra(0)
	, m_col(0)
{

}

CRecomendaciones::~CRecomendaciones()
{
}

void CRecomendaciones::asignarVariables(char* titulo, double cal, double calr , double carb, double gt, double gs, double gpi, double gmi, double gts ,double fib, double col)
{
	m_titulo = titulo;
	m_cal = cal;
	m_cal_resta = calr;
	m_carbo = carb;
	m_gt = gt;
	m_gs = gs;
	m_gpi = gpi;
	m_gmi = gmi;
	m_gtrans = gts;
	m_fibra = fib;
	m_col = col;
	UpdateData(false);
}

void CRecomendaciones::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_TITULO, m_titulo);
	DDX_Text(pDX, IDC_EDIT2, m_cal);
	DDX_Text(pDX, IDC_EDIT3, m_cal_resta);
	DDX_Text(pDX, IDC_EDIT4, m_carbo);
	DDX_Text(pDX, IDC_EDIT5, m_gt);
	DDX_Text(pDX, IDC_EDIT6, m_gs);
	DDX_Text(pDX, IDC_EDIT8, m_gpi);
	DDX_Text(pDX, IDC_EDIT9, m_gmi);
	DDX_Text(pDX, IDC_EDIT10, m_gtrans);
	DDX_Text(pDX, IDC_EDIT11, m_fibra);
	DDX_Text(pDX, IDC_EDIT12, m_col);
}


BEGIN_MESSAGE_MAP(CRecomendaciones, CDialogEx)
END_MESSAGE_MAP()


// CRecomendaciones message handlers
