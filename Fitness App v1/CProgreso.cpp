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
{

}

CProgreso::~CProgreso()
{
}

void CProgreso::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProgreso, CDialogEx)
END_MESSAGE_MAP()


// CProgreso message handlers
