#pragma once


// CDatosUsuario dialog

class CDatosUsuario : public CDialogEx
{
	DECLARE_DYNAMIC(CDatosUsuario)

public:
	CDatosUsuario(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDatosUsuario();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATOSUSER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
