#pragma once


// CProgreso dialog

class CProgreso : public CDialogEx
{
	DECLARE_DYNAMIC(CProgreso)

public:
	CProgreso(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CProgreso();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRESO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
