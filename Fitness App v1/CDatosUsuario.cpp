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
{

}

CDatosUsuario::~CDatosUsuario()
{
}

void CDatosUsuario::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDatosUsuario, CDialogEx)
END_MESSAGE_MAP()


// CDatosUsuario message handlers
