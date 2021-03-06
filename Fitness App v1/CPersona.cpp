#include "stdafx.h"
#include "CPersona.h"


CPersona::CPersona()
{
	m_caloriasQuemadas = 0;
}

CPersona::~CPersona()
{
}

void CPersona::asignarEdad(int e)
{
	m_edad = e;
}

void CPersona::asignarEstatura(double est)
{
	m_estatura = est;
}

void CPersona::asignarPeso(double p)
{
	m_peso = p;
}

void CPersona::asignarSexo(char s)
{
	m_sexo = s;
}

void CPersona::asignarTramoRecorido(int p, CTiempo temp)
{
	m_tramo_recorido = ((temp.obtenerMinTotales() * 5) / 60);
}

void CPersona::asignarCaloriasIng(double cal)
{
	m_caloriasIng = cal;
}

void CPersona::asignarCaloriasRecom(double cal)
{
	m_caloriasRecom = cal;
}

void CPersona::asignarCondicion(int x)
{
	m_condicion = x;
}

void CPersona::asignarPasos(int p)
{
	m_pasos = p;
}

void CPersona::asignarPasosMeta(int p)
{
	m_metaPasos = p;
}

void CPersona::asignarProposito(int p)
{
	m_proposito = p;
	// 1 - Bajar de Peso 2 - Elevar Rendimiento 3 - Mantenimineto 4 - Prescripcion Medica
}

void CPersona::asignarCalQuemadasAF(int caso)
{
	switch (caso){
		case 1:
		m_caloriasQuemadas += ((duracionActividadFisica.obtenerMinTotales() * 150) / 32);
		break;
	case 2:
		m_caloriasQuemadas += ((duracionActividadFisica.obtenerMinTotales() * 150) / 27);
		break;
	case 3:
		m_caloriasQuemadas += ((duracionActividadFisica.obtenerMinTotales() * 150) / 19);
		break;
	default:
		m_caloriasQuemadas += ((duracionActividadFisica.obtenerMinTotales() * 150) / 12);
		break;
	}
}

void CPersona::asignarCalQuemadasPasos()
{
	m_caloriasQuemadas += ((duracionActividadPasos.obtenerMinTotales() * 150) / 43);
}



void CPersona::asignarDuracionAF(int horas, int minutos, int segundos)
{
	duracionActividadFisica.asignarHoras(horas);
	duracionActividadFisica.asignarMinutos(minutos);
	duracionActividadFisica.asignarSegundos(segundos);
}

void CPersona::asignarDuracionP(int horas, int minutos, int segundos)
{
	duracionActividadPasos.asignarHoras(horas);
	duracionActividadPasos.asignarMinutos(minutos);
	duracionActividadPasos.asignarSegundos(segundos);
}

void CPersona::asignarDuracionAF2(int horas, int minutos, int segundos)
{
	duracionActividadFisica2.asignarHoras(horas);
	duracionActividadFisica2.asignarMinutos(minutos);
	duracionActividadFisica2.asignarSegundos(segundos);
}

void CPersona::asignarDuracionP2(int horas, int minutos, int segundos)
{
	duracionActividadPasos2.asignarHoras(horas);
	duracionActividadPasos2.asignarMinutos(minutos);
	duracionActividadPasos2.asignarSegundos(segundos);
}

void CPersona::asignarActividadProm(int act)
{	//1 - Actividad Ligera 2 - Actividad moderada 3 - Actividad intensa 4 - Actividad extremadamente alta 5 - Ninguna
	m_activdadprom = act;
	switch (act) {
	case 1:
		m_factor = (1.375);
		break;
	case 2:
		m_factor = (1.55);
		break;
	case 3:
		m_factor = (1.725);
		break;
	case 4:
		m_factor = (1.9);
		break;
	default:
		m_factor = (1.2);
		break;
	}
}
void CPersona::asignarActividad(int a)
{
	m_actividad = a;
}

void CPersona::calcularRegimen()
{
	
}



void CPersona::calcularCalorias()
{
	//Formula de Harris - Benedict
	if (m_sexo == 'm') {
		m_caloriasRecom = ((655 + (9.6 * m_peso)) + ((1.8 *(m_estatura * 100)) - (4.7 * m_edad)) * m_factor);
	}
	else {
		m_caloriasRecom = ((66 + (13.7 * m_peso)) + ((5 *(m_estatura * 100)) - (6.8 * m_edad)) * m_factor);
	}
}

void CPersona::asignarNombre(char temp [50])
{
	strcpy(m_nombre, temp);
}


int CPersona::obtenerEdad()
{
	return m_edad;
}

int CPersona::obtenerCondicion()
{
	return m_condicion;
}

int CPersona::obtenerActividad()
{
	return m_actividad;
}

int CPersona::obtenerActividadProm()
{
	return m_activdadprom;
}

double CPersona::obtenerEstatura()
{
	return m_estatura;
}

double CPersona::obtenerPeso()
{
	return m_peso;
}

double CPersona::obtenerIMC()
{
	m_imc = m_peso / (m_estatura * m_estatura);
	return m_imc;
}

int CPersona::obtenerPasos()
{
	return m_pasos;
}

int CPersona::obtenerPasosMeta()
{
	return m_metaPasos;
}

double CPersona::obttenerTramo()
{
	return m_tramo_recorido;
}

double CPersona::obtenerCaloriasIng()
{
	return m_caloriasIng;
}

double CPersona::obtenerCaloriasRecom()
{
	return m_caloriasRecom;
}

int CPersona::obtenerProposito()
{
	return m_proposito;
}

char  CPersona::obtenerSexo()
{
	return m_sexo;
}

char * CPersona::obtenerNombre()
{
	return m_nombre;
}

char * CPersona::riesgoImc()
{
	char* temp;
	if (m_sexo == 'm') {
		if (m_imc < 20) {
			temp = "Peso Bajo";
		}
		else if (m_imc >= 20 && m_imc < 25) {
			temp = "Normal";
		}
		else if (m_imc >= 25 && m_imc < 30) {
			temp = "Obesidad Leve";
		}
		else if (m_imc >= 30 && m_imc < 40) {
			temp = "Obesidad Moderada";
		}
		else {
			temp = "Obesidad Severa";
		}
	}
	else {
		if (m_imc < 20) {
			temp = "Peso Bajo";
		}
		else if (m_imc >= 20 && m_imc < 24) {
			temp = "Normal";
		}
		else if (m_imc >= 24 && m_imc < 29) {
			temp = "Obesidad Leve";
		}
		else if (m_imc >= 29 && m_imc < 37) {
			temp = "Obesidad Moderada";
		}
		else {
			temp = "Obesidad Severa";
		}
	}

	return temp;
}
