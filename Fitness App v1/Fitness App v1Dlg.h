
// Fitness App v1Dlg.h : header file
//

#pragma once

#include "CDatosUsuario.h"
#include "CMetaDiariaCal.h"
#include "CMetaDiariaIng.h"
#include "CProgreso.h"
#include "CRecomendaciones.h"
#include "CPersona.h"
#include "CUserSelec.h"
#include "CUsuarios.h"
#include "CDesarollo.h"


// CFitnessAppv1Dlg dialog
class CFitnessAppv1Dlg : public CDialogEx
{
// Construction
public:
	CFitnessAppv1Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FITNESSAPPV1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_users = 0, m_current_user;
protected:
	CTabCtrl m_tabCtrl;
private:
	CDatosUsuario m_datos;
	CMetaDiariaIng m_meta_ing;
	CMetaDiariaCal m_meta_cal;
	CRecomendaciones m_recom;
	CProgreso m_progreso;
	CWnd* m_pwndShow;
	CUsuarios m_dialogo;
	CPersona user[10];
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnUsuariosNuevousuario();
	afx_msg void OnUsuariosModificarusuario();
	afx_msg void OnDesarolladorIngresodatos();
	friend class CUsuarios;

private:
	CUserSelec m_user_selec;
public:
	afx_msg void OnArchivoCargararchivo();
	afx_msg void OnArchivoGuardararchivo();
private:
	CDesarollo m_desarollo;
};
