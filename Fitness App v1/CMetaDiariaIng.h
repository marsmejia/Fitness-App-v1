#pragma once


// CMetaDiariaIng dialog

class CMetaDiariaIng : public CDialogEx
{
	DECLARE_DYNAMIC(CMetaDiariaIng)

public:
	CMetaDiariaIng(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMetaDiariaIng();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_METADIARIA_I };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
