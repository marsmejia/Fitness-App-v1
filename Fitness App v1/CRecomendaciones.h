#pragma once


// CRecomendaciones dialog

class CRecomendaciones : public CDialogEx
{
	DECLARE_DYNAMIC(CRecomendaciones)

public:
	CRecomendaciones(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CRecomendaciones();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RECOMENDACIONES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
