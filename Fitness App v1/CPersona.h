#pragma once
#include "CTiempo.h"
#include "CDieta.h"
class CPersona
{
	double m_estatura, m_peso, m_tramo_recorido, m_caloriasIng, m_caloriasRecom, m_imc, m_factor, m_caloriasQuemadas;
	int m_edad, m_condicion, m_pasos, m_proposito, m_activdadprom, m_actividad, m_metaPasos;
	char m_sexo;
	char m_nombre[50];
	CTiempo duracionActividadFisica, duracionActividadPasos, duracionActividadFisica2, duracionActividadPasos2;
	CDieta dieta;
	friend class CFitnessAppv1Dlg;
	friend class CUsuarios;
	friend class CDatosUsuario;
	friend class CMetaDiariaCal;

public:
	CPersona();
	~CPersona();
	void asignarEdad(int);
	void asignarEstatura(double);
	void asignarPeso(double);
	void asignarSexo(char);
	void asignarTramoRecorido(int, CTiempo);
	void asignarCaloriasIng(double);
	void asignarCaloriasRecom(double);
	void asignarCondicion(int);
	void asignarPasos(int);
	void asignarPasosMeta(int);
	void asignarProposito(int);
	void asignarCalQuemadasAF(int);
	void asignarCalQuemadasPasos();
	void asignarDuracionAF(int, int, int);
	void asignarDuracionP(int, int, int);
	void asignarDuracionAF2(int, int, int);
	void asignarDuracionP2(int, int, int);
	void asignarActividadProm(int);
	void asignarActividad(int);
	void calcularRegimen();
	void calcularCalorias();
	void asignarNombre(char[50]);
	

	int obtenerEdad();
	int obtenerCondicion();
	int obtenerActividad();
	int obtenerActividadProm();
	double obtenerEstatura();
	double obtenerPeso();
	double obtenerIMC();
	int obtenerPasos();
	int obtenerPasosMeta();
	double obttenerTramo();
	double obtenerCaloriasIng();
	double obtenerCaloriasRecom();
	int obtenerProposito();
	char obtenerSexo();
	char* obtenerNombre();
	char* riesgoImc();
};

