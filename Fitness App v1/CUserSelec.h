#pragma once


// CUserSelec dialog

class CUserSelec : public CDialogEx
{
	DECLARE_DYNAMIC(CUserSelec)

public:
	CUserSelec(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUserSelec();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER_SELEC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CListBox m_lista_users;
public:
	void agregarUsuarios(char [50], int);
	void limpiar();
	afx_msg void OnBnClickedSelec();
	afx_msg void OnBnClickedBorrar();
	int m_users, m_current_user;
	int m_deleted_users;
	bool update;
};
