#pragma once
class CTiempo
{
	int m_horas, m_minutos, m_segundos;
public:
	CTiempo();
	CTiempo(int);
	CTiempo(int, int, int);
	~CTiempo();

	void asignarHoras(int);
	void asignarMinutos(int);
	void asignarSegundos(int);
	void asignarTodo(int, int, int);
	void asignarMinTotales(int);

	int obtenerHoras();
	int obtenerMinutos();
	int obtenerSegundos();
	double obtenerMinTotales();

	void mostrarTiempo();
	void temporizador(bool);
};

