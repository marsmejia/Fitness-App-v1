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
	//1 - Actividad Ligera 2 - Actividad moderada 3 - Actividad intensa 4 - Actividad extremadamente alta 5 - Ninguna
	// 1 - Diabetes 2 - Hipertension 3 - Artritis 4 - Embarazo
	// 1 - Bajar de Peso 2 - Elevar Rendimiento 3 - Mantenimineto 4 - Prescripcion Medica
	/*switch (m_proposito) {
	default:
		switch (m_condicion) {
		case 0 :
			cout << "Te recomendamos hacer una actividad fisica ";
			imprimirActividad(m_activdadprom);
			m_actividad = m_activdadprom;
			cout << endl << "De duracion de ";
			duracionActividadFisica2.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << m_pasos << " pasos en menos de ";
			duracionActividadPasos2.mostrarTiempo();
			break;
		case 1:
			cout << "Te recomendamos hacer una actividad fisica ";
			imprimirActividad(2);
			m_actividad = 2;
			cout << endl << "De duracion de ";
			duracionActividadFisica.asignarTodo(0, 30, 0);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << 2000 << " pasos en menos de ";
			duracionActividadPasos.asignarTodo(1, 0, 0);
			duracionActividadPasos.mostrarTiempo();
			break;
		case 2:
			cout << "Te recomendamos hacer una actividad fisica ";
			imprimirActividad(2);
			m_actividad = 2;
			cout << endl << "De duracion de ";
			duracionActividadFisica.asignarTodo(1, 15, 0);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << 3000 << " pasos en menos de ";
			duracionActividadPasos.asignarTodo(2, 0, 0);
			duracionActividadPasos.mostrarTiempo();
			break;
		case 3:
			cout << "Te recomendamos hacer una actividad fisica ";
			imprimirActividad(1);
			m_actividad = 1;
			cout << endl << "De duracion de ";
			duracionActividadFisica.asignarTodo(0, 30, 0);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << 5000 << " pasos en menos de ";
			duracionActividadPasos.asignarTodo(6, 0, 0);
			duracionActividadPasos.mostrarTiempo();
			break;
		case 4:
			cout << "Te recomendamos hacer una actividad fisica ";
			imprimirActividad(1);
			m_actividad = 1;
			cout << endl << "De duracion de ";
			duracionActividadFisica.asignarTodo(0, 15, 0);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << 3500 << " pasos en menos de ";
			duracionActividadPasos.asignarTodo(8, 0, 0);
			duracionActividadPasos.mostrarTiempo();
			break;
		}
		break;
	case 1:
		switch (m_condicion) {
		case 0:
			int minutos, actividad;
			cout << "Te recomendamos hacer una actividad fisica ";
			if (m_actividad < 3) {
				actividad = (m_activdadprom + 1);
			}
			else {
				actividad = m_activdadprom;
			}
			m_actividad = m_activdadprom;
			imprimirActividad(actividad);
			cout << endl << "De duracion de ";
			minutos = duracionActividadFisica2.obtenerMinTotales() + 15;
			duracionActividadFisica.asignarMinTotales(minutos);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << m_pasos + 1000 << " pasos en menos de ";
			duracionActividadPasos2.mostrarTiempo();
			break;
		case 1:
			cout << "Te recomendamos hacer una actividad fisica ";
			imprimirActividad(2);
			m_actividad = 2;
			cout << endl << "De duracion de ";
			duracionActividadFisica.asignarTodo(0, 30, 0);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << 3000 << " pasos en menos de ";
			duracionActividadPasos.asignarTodo(1, 0, 0);
			duracionActividadPasos.mostrarTiempo();
			break;
		case 2:
			cout << "Te recomendamos hacer una actividad fisica ";
			imprimirActividad(2);
			m_actividad = 2;
			cout << endl << "De duracion de ";
			duracionActividadFisica.asignarTodo(1, 0, 0);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << 4000 << " pasos en menos de ";
			duracionActividadPasos.asignarTodo(2, 0, 0);
			duracionActividadPasos.mostrarTiempo();
			break;
		case 3:
			cout << "Te recomendamos hacer una actividad fisica ";
			imprimirActividad(1);
			m_actividad = 1;
			cout << endl << "De duracion de ";
			duracionActividadFisica.asignarTodo(0, 30, 0);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << 6000 << " pasos en menos de ";
			duracionActividadPasos.asignarTodo(6, 0, 0);
			duracionActividadPasos.mostrarTiempo();
			break;
		case 4:
			cout << "Te recomendamos hacer una actividad fisica ";
			imprimirActividad(1);
			m_actividad = 1;
			cout << endl << "De duracion de ";
			duracionActividadFisica.asignarTodo(0, 25, 0);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << 5000 << " pasos en menos de ";
			duracionActividadPasos.asignarTodo(8, 0, 0);
			duracionActividadPasos.mostrarTiempo();
			break;
		}
		break;
	case 2:
		switch (m_condicion) {
		case 0:
			int minutos, actividad;
			cout << "Te recomendamos hacer una actividad fisica ";
			if (m_actividad < 4) {
				actividad = (m_activdadprom + 1);
			}
			else {
				actividad = m_activdadprom;
			}
			m_actividad = m_activdadprom;
			imprimirActividad(actividad);
			cout << endl << "De duracion de ";
			minutos = duracionActividadFisica2.obtenerMinTotales() + 20;
			duracionActividadFisica.asignarMinTotales(minutos);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << m_pasos + 2000 << " pasos en menos de ";
			duracionActividadPasos2.mostrarTiempo();
			break;
		case 1:
			cout << "Te recomendamos hacer una actividad fisica ";
			imprimirActividad(2);
			m_actividad = 2;
			cout << endl << "De duracion de ";
			duracionActividadFisica.asignarTodo(0, 30, 0);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << 3000 << " pasos en menos de ";
			duracionActividadPasos.asignarTodo(1, 0, 0);
			duracionActividadPasos.mostrarTiempo();
			break;
		case 2:
			cout << "Te recomendamos hacer una actividad fisica ";
			imprimirActividad(2);
			m_actividad = 2;
			cout << endl << "De duracion de ";
			duracionActividadFisica.asignarTodo(1, 0, 0);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << 4000 << " pasos en menos de ";
			duracionActividadPasos.asignarTodo(2, 0, 0);
			duracionActividadPasos.mostrarTiempo();
			break;
		case 3:
			cout << "Te recomendamos hacer una actividad fisica ";
			imprimirActividad(1);
			m_actividad = 1;
			cout << endl << "De duracion de ";
			duracionActividadFisica.asignarTodo(0, 30, 0);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << 6000 << " pasos en menos de ";
			duracionActividadPasos.asignarTodo(6, 0, 0);
			duracionActividadPasos.mostrarTiempo();
			break;
		case 4:
			cout << "Te recomendamos hacer una actividad fisica ";
			imprimirActividad(1);
			m_actividad = 1;
			cout << endl << "De duracion de ";
			duracionActividadFisica.asignarTodo(0, 25, 0);
			duracionActividadFisica.mostrarTiempo();
			cout << endl << "Y caminar por lo menos " << 5000 << " pasos en menos de ";
			duracionActividadPasos.asignarTodo(8, 0, 0);
			duracionActividadPasos.mostrarTiempo();
			break;
		}
		break;
	}*/

}

void CPersona::calcularDieta()
{
	// caloriasIng caloriasRecom caloriasQuemadas proposito condicion
	dieta.calcularDieta(m_caloriasIng, m_caloriasRecom, m_caloriasQuemadas, m_proposito, m_condicion, m_edad);
	dieta.imprimirDieta();
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