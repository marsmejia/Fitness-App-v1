#pragma once
class CDieta
{
	double m_carbohidratos, m_proteinas, m_grasasSaturadas, m_grasaspoli, m_grasasmono, m_grasastrans, m_grasastotales, m_fibra, m_colesterol;
	int m_condicion;
	double m_caloriasRecom, m_calorias;

public:
	CDieta();
	~CDieta();
	void calcularDieta(double, double, double, int, int, int);
	char* imprimirDieta();
	friend class CFitnessAppv1Dlg;
};

