// CUserSelec.cpp : implementation file
//

#include "stdafx.h"
#include "Fitness App v1.h"
#include "CUserSelec.h"
#include "afxdialogex.h"


// CUserSelec dialog

IMPLEMENT_DYNAMIC(CUserSelec, CDialogEx)

CUserSelec::CUserSelec(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USER_SELEC, pParent)
{
}

CUserSelec::~CUserSelec()
{
}

void CUserSelec::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LST, m_lista_users);
}


BEGIN_MESSAGE_MAP(CUserSelec, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LST, &CUserSelec::OnLbnSelchangeLst)
END_MESSAGE_MAP()


// CUserSelec message handlers


void CUserSelec::OnLbnSelchangeLst()
{
	// TODO: Add your control notification handler code here
}

void CUserSelec::agregarUsuarios(char name[50], int usernum) {
	CString temp, temp2, temp3;
	temp = CString(name, 50);
	temp2.Format(_T("Usuario : %d"), usernum);
	temp3 = temp + temp2;
	m_lista_users.AddString(temp3);
}
