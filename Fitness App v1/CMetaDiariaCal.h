#pragma once


// CMetaDiariaCal dialog

class CMetaDiariaCal : public CDialogEx
{
	DECLARE_DYNAMIC(CMetaDiariaCal)

public:
	CMetaDiariaCal(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMetaDiariaCal();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_METADIARIA_C };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
