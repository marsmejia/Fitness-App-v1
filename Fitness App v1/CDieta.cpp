#include "stdafx.h"
#include "CDieta.h"


CDieta::CDieta()
{
}


CDieta::~CDieta()
{
}

void CDieta::calcularDieta(double ing, double recom, double quemadas, int proposito, int condicion, int edad)
{
	// caloriasIng caloriasRecom caloriasQuemadas proposito condicion
	// 1 - Bajar de Peso 2 - Elevar Rendimiento 3 - Mantenimineto 4 - Prescripcion Medica
	// 1 - Diabetes 2 - Hipertension 3 - Artritis 4 - Embarazo
	double caloriast = (recom - ing - quemadas);
	if (proposito == 1) {
		caloriast -= 500;
	}
	m_caloriasRecom = recom;
	m_calorias = caloriast;
	m_condicion = condicion;
	switch (condicion) {
	default: 
		m_carbohidratos = (caloriast * 0.65);
		m_grasasSaturadas = (caloriast * 0.07);
		m_grasaspoli = (caloriast * 0.1);
		m_grasasmono = (caloriast * 0.2);
		m_grasastrans = (caloriast * 0.01);
		m_grasastotales = (caloriast * 0.35);
		m_fibra = 20;
		m_colesterol = 300;
		if (edad < 3) {
			m_proteinas = (caloriast * 0.15);
		}
		else if (edad > 3 || edad < 18) {
			m_proteinas = (caloriast * 0.3);
		}
		else {
			m_proteinas = (caloriast * 0.35);
		}
		break;
	case 1:
		m_carbohidratos = (caloriast * 0.65);
		m_grasasSaturadas = (caloriast * 0.05);
		m_grasaspoli = (caloriast * 0.1);
		m_grasasmono = (caloriast * 0.15);
		m_grasastrans = (caloriast * 0.01);
		m_grasastotales = (caloriast * 0.28);
		m_fibra = 20 + (14*(caloriast / 1000));
		m_colesterol = 150;
		if (edad < 3) {
			m_proteinas = (caloriast * 0.15);
		}
		else if (edad > 3 || edad < 18) {
			m_proteinas = (caloriast * 0.3);
		}
		else {
			m_proteinas = (caloriast * 0.35);
		}
		break;
	case 2:
		m_carbohidratos = (caloriast * 0.5);
		m_grasasSaturadas = (caloriast * 0.07);
		m_grasaspoli = (caloriast * 0.1);
		m_grasasmono = (caloriast * 0.18);
		m_grasastrans = (caloriast * 0.01);
		m_grasastotales = (caloriast * 0.3);
		m_fibra = 20;
		m_colesterol = 150;
		m_proteinas = (caloriast * 0.35);
		break;
	case 4:
		m_carbohidratos = (caloriast * 0.65);
		m_grasasSaturadas = (caloriast * 0.07);
		m_grasaspoli = (caloriast * 0.1);
		m_grasasmono = (caloriast * 0.2);
		m_grasastrans = (caloriast * 0.01);
		m_grasastotales = (caloriast * 0.35);
		m_fibra = 20 + (20 * (caloriast / 1000));
		m_colesterol = 200;
		if (edad > 12 || edad < 18) {
			m_proteinas = (caloriast * 0.3);
		}
		else {
			m_proteinas = (caloriast * 0.35);
		}
		break;
	}

}

char* CDieta::imprimirDieta()
{
	switch(m_condicion){
	default:
		return "Te recomendamos lo siguente : ";
		break;
	case 1:
		return "Debido a que tienes diabetes te recomendamos lo siguente : ";
		break;
	case 2:
		return "Debido a que tienes hipertension te recomendamos lo siguente : ";
		break;
	case 4:
		return "Debido a que estas embarazada te recomendamos lo siguente : ";
		break;
	}
}
