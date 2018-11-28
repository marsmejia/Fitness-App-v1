#include "stdafx.h"
#include "CTiempo.h"



CTiempo::CTiempo()
{
}

CTiempo::CTiempo(int seg)
{
	m_horas = seg / 3600;
	m_minutos = seg / 60;
	m_segundos = seg % 60;
}

CTiempo::CTiempo(int h, int m, int s)
{
	m_horas = h;
	m_minutos = m;
	m_segundos = s;
}


CTiempo::~CTiempo()
{
}

void CTiempo::asignarHoras(int h)
{
	m_horas = h;
}

void CTiempo::asignarMinutos(int m)
{
	m_minutos = m;
}

void CTiempo::asignarSegundos(int s)
{
	m_segundos = s;
}

void CTiempo::asignarTodo(int h, int m, int s)
{
	m_horas = h;
	m_minutos = m;
	m_segundos = s;
}

void CTiempo::asignarMinTotales(int min)
{

	m_horas = (min / 60);
	m_minutos = (min - (m_horas * 60));
	m_segundos = 0;
}

int CTiempo::obtenerHoras()
{
	return m_horas;
}

int CTiempo::obtenerMinutos()
{
	return m_minutos;
}

int CTiempo::obtenerSegundos()
{
	return m_segundos;
}

int CTiempo::obtenerMinTotales()
{
	return ((m_horas * 60) + m_minutos);
}

void CTiempo::mostrarTiempo()
{
	//cout << m_horas << " horas " << m_minutos << " minutos y " << m_segundos << " segundos ";
}

void CTiempo::temporizador(bool en)
{
	if (en) {
		m_segundos++;
		if (m_segundos == 60) {
			m_minutos++;
			m_segundos = 0;
		}

		if (m_minutos == 60)
		{
			m_horas++;
			m_minutos = 0;
			m_segundos = 0;
		}

		if (m_horas == 24)
		{
			m_segundos = 0;
			m_minutos = 0;
			m_horas = 0;
		}
	}
}
