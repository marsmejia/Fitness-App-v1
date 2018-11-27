#pragma once


// CDesarollo dialog

class CDesarollo : public CDialogEx
{
	DECLARE_DYNAMIC(CDesarollo)

public:
	CDesarollo(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDesarollo();
	friend class CFitnessAppv1Dlg;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CPersona usuario;
	DECLARE_MESSAGE_MAP()
};
