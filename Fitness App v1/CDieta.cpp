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
	else if (proposito == 4) {
		//cout << "Ingrese su restriccion calorica : ";
		//cin >> caloriast;
		//cout << endl;
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

void CDieta::imprimirDieta()
{
	/*switch(m_condicion){
	default:
		cout << "Te recomendamos lo siguente : " << endl;
		break;
	case 1:
		cout << "Debido a que tienes diabetes te recomendamos lo siguente : " << endl;
		break;
	case 2:
		cout << "Debido a que tienes hipertension te recomendamos lo siguente : " << endl;
		break;
	case 4:
		cout << "Debido a que estas embarazada te recomendamos lo siguente : " << endl;
		break;

	}
	cout << "La cantidad recomendada de calorias es  : " << m_caloriasRecom << "kcal" << endl;
	cout << "De las cuales te faltan : " << m_calorias << "kcal por consumir" << endl;
	cout << "La cantidad de carbohidratos recomendados : " << m_carbohidratos << "kcal" << endl;
	cout << "La cantidad de grasas totales : " << m_grasastotales << "kcal" << endl;
	cout << "La cantidad de proteinas : " << m_proteinas << "kcal" << endl;
	cout << "La cantidad de grasas saturadas : " << m_grasasSaturadas << "kcal" << endl;
	cout << "La cantidad de grasas poli - insaturadas : " << m_grasaspoli << "kcal" << endl;
	cout << "La cantidad de grasas mono - insaturadas : " << m_grasasmono << "kcal" << endl;
	cout << "La cantidad de grasas trans : " << m_grasastrans << "kcal" << endl;
	cout << "La cantidad de fibra : " << m_fibra << "gr" << endl;
	cout << "La cantidad de colesterol : " << m_colesterol << "mg" << endl;
	*/
}
