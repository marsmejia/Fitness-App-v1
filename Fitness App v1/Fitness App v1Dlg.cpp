
// Fitness App v1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Fitness App v1.h"
#include "Fitness App v1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFitnessAppv1Dlg dialog



CFitnessAppv1Dlg::CFitnessAppv1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FITNESSAPPV1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFitnessAppv1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabCtrl);
}

BEGIN_MESSAGE_MAP(CFitnessAppv1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CFitnessAppv1Dlg::OnTcnSelchangeTab1)
	ON_COMMAND(ID_USUARIOS_NUEVOUSUARIO, &CFitnessAppv1Dlg::OnUsuariosNuevousuario)
	ON_COMMAND(ID_USUARIOS_MODIFICARUSUARIO, &CFitnessAppv1Dlg::OnUsuariosModificarusuario)
	ON_COMMAND(ID_DESAROLLADOR_INGRESODATOS, &CFitnessAppv1Dlg::OnDesarolladorIngresodatos)
	ON_COMMAND(ID_ARCHIVO_CARGARARCHIVO, &CFitnessAppv1Dlg::OnArchivoCargararchivo)
	ON_COMMAND(ID_ARCHIVO_GUARDARARCHIVO, &CFitnessAppv1Dlg::OnArchivoGuardararchivo)
END_MESSAGE_MAP()


// CFitnessAppv1Dlg message handlers

BOOL CFitnessAppv1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_tabCtrl.InsertItem(0,_T("Datos del Usuario"),0);
	m_tabCtrl.InsertItem(1, _T("Cambio de Usuario"), 1);
	m_tabCtrl.InsertItem(2, _T("Ingreso de Meta Diaria"), 2);
	m_tabCtrl.InsertItem(3, _T("Calculo de la Meta Diaria"), 3);
	m_tabCtrl.InsertItem(4, _T("Progreso del dia"), 4);
	m_tabCtrl.InsertItem(5, _T("Recomendaciones diarias"), 5);

	CRect rect;
	m_tabCtrl.GetClientRect(&rect);
	m_datos.Create(IDD_DATOSUSER, &m_tabCtrl);
	m_datos.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 10, SWP_SHOWWINDOW || SWP_NOZORDER);

	m_meta_ing.Create(IDD_METADIARIA_I, &m_tabCtrl);
	m_meta_ing.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 10, SWP_SHOWWINDOW || SWP_NOZORDER);

	m_meta_cal.Create(IDD_METADIARIA_C, &m_tabCtrl);
	m_meta_cal.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 10, SWP_SHOWWINDOW || SWP_NOZORDER);

	m_progreso.Create(IDD_PROGRESO, &m_tabCtrl);
	m_progreso.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 10, SWP_SHOWWINDOW || SWP_NOZORDER);

	m_recom.Create(IDD_RECOMENDACIONES, &m_tabCtrl);
	m_recom.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 10, SWP_SHOWWINDOW || SWP_NOZORDER);

	m_user_selec.Create(IDD_USER_SELEC, &m_tabCtrl);
	m_user_selec.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 10, SWP_SHOWWINDOW || SWP_NOZORDER);
	
	m_datos.ShowWindow(SW_SHOW);
	m_pwndShow = &m_datos;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFitnessAppv1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFitnessAppv1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFitnessAppv1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//Tabs
void CFitnessAppv1Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here

	m_datos.usuario = user[m_current_user];
	m_datos.cargarDatos(m_current_user);
	if (m_pwndShow != NULL) {
		m_pwndShow -> ShowWindow(SW_HIDE);
		m_pwndShow = NULL;
	}

	int nIndex = m_tabCtrl.GetCurSel();
	switch (nIndex) {
	case 0:
		m_datos.ShowWindow(SW_SHOW);
		m_pwndShow = &m_datos;
		break;
	case 1:
		if (m_users == 0) {
			int resp;
			resp = AfxMessageBox(_T("No existen usuarios, agrega uno."), MB_OK | MB_ICONEXCLAMATION);
			m_datos.ShowWindow(SW_SHOW);
			m_pwndShow = &m_datos;
			m_tabCtrl.SetCurSel(0);
		}
		else {
			m_user_selec.limpiar();
			for (int i = 1; i < m_users +1; i++) {
				char temp[50];
				CStringA tempString;
				tempString = user[i].obtenerNombre();
				strcpy_s(temp, tempString.GetString());
				m_user_selec.agregarUsuarios(temp, i);
				m_user_selec.m_current_user = m_current_user;
			}
			m_user_selec.ShowWindow(SW_SHOW);
			m_pwndShow = &m_user_selec;
		}
		break;
	case 2:
		m_meta_ing.usuario = user[m_current_user];
		m_meta_ing.ShowWindow(SW_SHOW);
		m_pwndShow = &m_meta_ing;
		break;
	case 3:
		m_meta_cal.usuario = user[m_current_user];
		m_meta_cal.calcular();
		m_meta_cal.ShowWindow(SW_SHOW);
		m_pwndShow = &m_meta_cal;
		break;
	case 4:
		m_progreso.asignar(user[m_current_user]);
		m_progreso.ShowWindow(SW_SHOW);
		m_pwndShow = &m_progreso;
		break;
	case 5:
		CDieta dieta;
		// caloriasIng caloriasRecom caloriasQuemadas proposito condicion
		double caling, calrecom, calquem;
		int prop, cond, edad;
		caling = user[m_current_user].obtenerCaloriasIng();
		calrecom = user[m_current_user].obtenerCaloriasRecom();
		calquem = user[m_current_user].m_caloriasQuemadas;
		prop = user[m_current_user].obtenerProposito();
		cond = user[m_current_user].obtenerCondicion();
		edad = user[m_current_user].obtenerEdad();
		dieta.calcularDieta(caling, calrecom, calquem, prop, cond, edad);
		double cal_resta = dieta.m_calorias - user[m_current_user].m_caloriasIng;
		m_recom.asignarVariables(dieta.imprimirDieta(), dieta.m_calorias, cal_resta, dieta.m_carbohidratos, dieta.m_grasastotales, dieta.m_grasasSaturadas,
			dieta.m_grasaspoli, dieta.m_grasasmono, dieta.m_grasastrans, dieta.m_fibra, dieta.m_colesterol);
		m_recom.ShowWindow(SW_SHOW);
		m_pwndShow = &m_recom;
		break;
	}
	*pResult = 0;
	if (m_meta_ing.modificacion == true){
		user[m_current_user] = m_meta_ing.usuario;
		m_meta_ing.modificacion = false;
	}
	if (m_user_selec.update == true) {
		m_current_user = m_user_selec.m_current_user;
		m_user_selec.update = false;
	}

	if (m_meta_cal.modificacion == true) {
		user[m_current_user] = m_meta_cal.usuario;
		m_meta_ing.modificacion = false;
	}
	if (m_users > m_user_selec.m_users) {
		for (int i = 1; i <= (m_users - m_user_selec.m_deleted_users) ; i++) {
			int valor = (m_user_selec.m_deleted_users + i);
			m_users[&valor - 1] = m_users[&valor];
		}
		m_users = m_user_selec.m_users;
	}
}
//Menu


void CFitnessAppv1Dlg::OnUsuariosNuevousuario()
{
	m_dialogo.asignarCaso(1, m_users + 1);
	m_dialogo.DoModal();

	if (m_dialogo.cancelar == false) {
		m_users++;
		m_current_user = m_users;
		user[m_users] = m_dialogo.usuario;
		m_datos.ShowWindow(SW_HIDE);
		m_datos.usuario = user[m_current_user];
		m_datos.cargarDatos(m_current_user);
		m_datos.ShowWindow(SW_SHOW);
		m_pwndShow = &m_datos;
	}
}


void CFitnessAppv1Dlg::OnUsuariosModificarusuario()
{
	if (m_users == 0) {
		int resp;
		resp = AfxMessageBox(_T("No existen usuarios, agrega uno."), MB_OK | MB_ICONEXCLAMATION);
	}
	else {
		m_dialogo.usuario = user[m_current_user];
		m_dialogo.asignarCaso(2, m_current_user);
		m_dialogo.DoModal();
		user[m_current_user] = m_dialogo.usuario;
		m_datos.ShowWindow(SW_HIDE);
		m_datos.usuario = user[m_current_user];
		m_datos.cargarDatos(m_current_user);
		m_datos.ShowWindow(SW_SHOW);
	}
}




void CFitnessAppv1Dlg::OnDesarolladorIngresodatos()
{
	m_desarollo.usuario = user[m_current_user];
	m_desarollo.DoModal();
	user[m_current_user] = m_desarollo.usuario;
}


void CFitnessAppv1Dlg::OnArchivoCargararchivo()
{
	FILE * users;
	int i = 1;
	double estatura, peso;
	int edad, condicion, proposito;
	char sexo;
	char nombre[50];
	errno_t err;
	//err = fopen_s(&users, "C:\\Users\\Zypher\\Desktop\\usuarios.txt", "r");
	err = fopen_s(&users, "C:\\Users\\Coolj\\Desktop\\usuarios.txt", "r");
	if (err != 0)
	{
		int resp;
		resp = AfxMessageBox(_T("Error al abrir el archivo!"), MB_OK | MB_ICONEXCLAMATION);
	}
	else {
		while (fscanf(users, "%s %c %lf %lf %d %d %d", nombre, &sexo, &estatura, &peso, &edad, &condicion, &proposito) != EOF) {
			user[i].asignarNombre(nombre);
			user[i].asignarSexo(sexo);
			user[i].asignarEstatura(estatura);
			user[i].asignarPeso(peso);
			user[i].asignarEdad(edad);
			user[i].asignarCondicion(condicion);
			user[i].asignarProposito(proposito);
			i++;
		}
		err = fclose(users);
		m_users = i - 1;
		m_current_user = 1;
		int resp;
		resp = AfxMessageBox(_T("El archivo ha sido cargado correctamente."), MB_OK | MB_ICONINFORMATION);
		m_datos.ShowWindow(SW_HIDE);
		m_datos.usuario = user[m_current_user];
		m_datos.cargarDatos(m_current_user);
		m_datos.ShowWindow(SW_SHOW);
	}
}


void CFitnessAppv1Dlg::OnArchivoGuardararchivo()
{
	FILE * users;
	int i = 1;
	double estatura, peso;
	int edad, condicion, proposito;
	char sexo;
	char nombre[50];
	errno_t err;
	//err = fopen_s(&users, "C:\\Users\\Zypher\\Desktop\\usuarios.txt", "w+");
	err = fopen_s(&users, "C:\\Users\\Coolj\\Desktop\\usuarios.txt", "w+");
	if (err != 0) {
		int resp;
		resp = AfxMessageBox(_T("Error al guardar el archivo!"), MB_OK | MB_ICONEXCLAMATION);
	}
	else {
		while (i <= m_users) {
			strcpy_s(nombre, user[i].obtenerNombre());
			estatura = user[i].obtenerEstatura();
			peso = user[i].obtenerPeso();
			edad = user[i].obtenerEdad();
			condicion = user[i].obtenerCondicion();
			sexo = user[i].obtenerSexo();
			proposito = user[i].obtenerProposito();
			fprintf(users, "%s %c %lf %lf %d %d %d \n", nombre, sexo, estatura, peso, edad, condicion, proposito);
			i++;
		}
		err = fclose(users);
		int resp;
		resp = AfxMessageBox(_T("El archivo ha sido guardado correctamente."), MB_OK | MB_ICONINFORMATION);
		m_datos.ShowWindow(SW_HIDE);
		m_datos.usuario = user[m_current_user];
		m_datos.cargarDatos(m_current_user);
		m_datos.ShowWindow(SW_SHOW);
	}
}
