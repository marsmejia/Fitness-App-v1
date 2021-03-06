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
	ON_BN_CLICKED(ID_SELEC, &CUserSelec::OnBnClickedSelec)
	ON_BN_CLICKED(ID_Borrar, &CUserSelec::OnBnClickedBorrar)
END_MESSAGE_MAP()


// CUserSelec message handlers



void CUserSelec::agregarUsuarios(char name[50], int usernum) {
	CString temp, temp2, temp3;
	temp = CString(name, 50);
	temp2.Format(_T("Usuario : %d "), usernum);
	temp3 = temp2 + temp;
	m_lista_users.AddString(temp3);
	m_users = usernum;
}

void CUserSelec::limpiar()
{
	m_lista_users.ResetContent();
}


void CUserSelec::OnBnClickedSelec()
{
	m_current_user = m_lista_users.GetCurSel() + 1;
	update = true;
}


void CUserSelec::OnBnClickedBorrar()
{
	CListBox *pListBox;
	pListBox = (CListBox *)GetDlgItem(IDC_LST);
	pListBox->DeleteString(m_lista_users.GetCurSel());
	m_users--;
	m_deleted_users = m_lista_users.GetCurSel();
}
