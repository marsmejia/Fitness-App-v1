/*#include "stdafx.h"

int usuarioActual = 0;
int numeroUsuarios = 0;
CPersona usuario[10];

void impresionTitulo(int, int);
void menu();
void creacionUsuario(CPersona &);
void imprimirUsuario(CPersona &);
void datosUsuario();
void modificarUsuario();
void agregarUsuario();
void cambiarUsuario();
void metaDiaria();
void metaCalculada();
void progresoDiario();
void guardarUsuarios();
void configuaraciones();
void continuar();


int main()
{
	system("cls");
	int selec;
	impresionTitulo(0, 0);
	cout << "Deseas intentar cargar un archivo de usuarios? ( 1 = Si / 0 = No ) ";
	cin >> selec;
	//Incializacion
	if (selec == 1) {
			FILE * users;
			int i = 1; 
			double estatura, peso;
			int edad, condicion, proposito;
			char sexo;
			char nombre[50];
			errno_t err;
			err = fopen_s(&users, "C:\\Users\\Zypher\\Desktop\\usuarios.txt", "r");
			if (err != 0)
			{
				cout << "\nError al cargar el archivo!";
			}
			while (fscanf(users, "%s %c %lf %lf %d %d %d", nombre, &sexo, &estatura, &peso, &edad, &condicion, &proposito) != EOF) {
				usuario[i].asignarNombre(nombre);
				usuario[i].asignarSexo(sexo);
				usuario[i].asignarEstatura(estatura);
				usuario[i].asignarPeso(peso);
				usuario[i].asignarEdad(edad);
				usuario[i].asignarCondicion(condicion);
				usuario[i].asignarProposito(proposito);
				i++;
			}
			err = fclose(users);
			numeroUsuarios =(i-1);
			usuarioActual = 1;
			cout << "\nArchivo Cargado!" << endl;
			continuar();
	}
	else {
		cout << "Antes de comenzar necesitamos un poco de informacion sobre ti!" << endl;
		cin.ignore();
		creacionUsuario(usuario[1]);
		cout << "\nEl usuario creado tiene las siguientes caracteristicas : " << endl;
		imprimirUsuario(usuario[1]);
		continuar();
		usuarioActual = 1;
		numeroUsuarios = 1;
	}
	//Menu
	menu();
	return 0;
}

void impresionTitulo(int x, int y) 
{
	cout << "|------------------------------------------------------------------------|" << endl;
	cout << "|                                                                        |" << endl;
	switch (x) {
		case 0:
			cout << "|                Bienvenido al Sistema Super Fitness 5000                |" << endl;
			break;
		case 1:
			cout << "|                       Sistema Super Fitness 5000                       |" << endl;
			break;
	}
	switch (y) {
		case 1:
			cout << "|                           Datos del Usuario                            |" << endl;
			break;
		case 2:
			cout << "|                           Modificar Usuario                            |" << endl;
			break;
		case 3:
			cout << "|                           Agregar Usuario                              |" << endl;
			break;
		case 4:
			cout << "|                          Cambiar de Usuario                            |" << endl;
			break;
		case 5:
			cout << "|                        Ingreso de Meta Diaria                          |" << endl;
			break;
		case 6:
			cout << "|                         Calculo de Meta Diaria                         |" << endl;
			break;
		case 7:
			cout << "|                            Progreso de Hoy                             |" << endl;
			break;
		case 8:
			cout << "|                        Recomendaciones Diarias                         |" << endl;
			break;
		case 9:
			cout << "|                           Guardar Usuarios                             |" << endl;
			break;
		case 10:
			cout << "|                            Configuraciones                             |" << endl;
			break;
		default:
		break;
	}
	cout << "|                                                                        |" << endl;
	cout << "|------------------------------------------------------------------------|" << endl;
	if (usuarioActual != 0) {
		cout << "Usuario : ";
		usuario[usuarioActual].imprimirNombre();
		cout << endl;
	}
}

void menu(){
	int opcion;
	system("cls");
	impresionTitulo(1, 0);
	cout << "Seleccione una opcion: \nl -  Si desea ver los datos del usuario." << endl;
	cout << "2 -  Si desea modificar el usuario" << endl;
	cout << "3 -  Si desea agregar otro usuario" << endl;
	cout << "4 -  Si desea cambiar de usuario" << endl;
	cout << "5 -  Si desea ingresar su meta diaria" << endl;
	cout << "6 -  Si desea calcular su meta diaria" << endl;
	cout << "7 -  Si desea ver su progreso de hoy" << endl;
	cout << "8 -  Si desea ver sus recomendaciones diarias" << endl;
	cout << "9 -  Si desea guardar los usuarios de la sesion" << endl;
	cout << "10 - Configuraciones" << endl;
	cout << "0 -  Si desea salir del programa" << endl;
	cout << "\nSu eleccion : ";
	cin >> opcion;
	while (opcion < 0 || opcion > 10) {
		cout << "Ingrese una seleccion valida!" << endl;
		cin >> opcion;
	}
	switch (opcion) {
	case 1:
		datosUsuario();
		break;
	case 2:
		modificarUsuario();
		break;
	case 3:
		agregarUsuario();
		break;
	case 4:
		cambiarUsuario();
		break;
	case 5:
		metaDiaria();
		break;
	case 6:
		metaCalculada();
		break;
	case 7:
		progresoDiario();
	break;
	case 8:
		system("cls");
		impresionTitulo(1, 8);
		usuario[usuarioActual].calcularDieta();
		continuar();
		menu();
		break;
	case 9:
		guardarUsuarios();
		break;
	case 10:
		configuaraciones();
		break;
	default:
		cout << "\nHasta pronto! :D" << endl;
		break;
	}
}


void creacionUsuario(CPersona &ref) {
	double estatura, peso;
	int edad, condicion, proposito;
	char sexo;
	ref.adquirirNombre();
	cout << "Por favor ingresa tu edad : ";
	cin >> edad;
	cout << "Por favor ingresa tu estatura en metros : ";
	cin >> estatura;
	cout << "Por favor ingresa tu peso en kilogramos : ";
	cin >> peso;
	cout << "Por favor ingresa tu sexo ( m = masculino , f = femenino) : ";
	cin >> sexo;
	cout << "Tienes alguna de las siguientes condiciones : " << endl;
	cout << "1 - Diabetes" << endl << "2 - Hipertension" << endl;
	cout << "3 - Artirtis" << endl;
	if (sexo == 'f') {
		cout << "4 - Estas embarazada" << endl;
	}
	cout << "Ingresa un 0 si no tienes ninguna de las anteriores " << endl;
	cin >> condicion;
	cout << "Cual es tu proposito para usar la aplicacion : " << endl;
	cout << "1 - Bajar de Peso \n2 - Elevar Rendimiento \n3 - Mantenimiento \n4 - Prescripcion Medica" << endl;
	cin >> proposito;
	ref.asignarEdad(edad);
	ref.asignarEstatura(estatura);
	ref.asignarPeso(peso);
	ref.asignarSexo(sexo);
	ref.asignarCondicion(condicion);
	ref.asignarProposito(proposito);
}

void imprimirUsuario(CPersona &ref) {
	cout << "El usuario es : ";
	ref.imprimirNombre();
	cout << endl;
	cout << "Tiene " << ref.obtenerEdad() << " anios" << endl;
	cout << "Mide " << ref.obtenerEstatura() << " m" << endl;
	cout << "Pesa " << ref.obtenerPeso() << " kg" << endl;
	cout << "Y su sexo es ";
	ref.imprimirSexo();
	cout << "Su indice de masa corporal es de : " << ref.obtenerIMC() << endl;
	cout << "Y se encuentra en el rango ";
	ref.imprimirRiesgoImc();
	
	switch (ref.obtenerCondicion()) {
	case 1:
		cout << "Tiene diabetes" << endl;
		break;
	case 2:
		cout << "Tiene hipertension" << endl;
		break;
	case 3:
		cout << "Tiene artritis" << endl;
		break;
	case 4:
		cout << "Esta embarazada" << endl;
		break;
	default:
		break;
	}
	// 1 - Diabetes 2 - Hipertension 3 - Artritis 4 - Embarazo
	cout << "Y su proposito es ";
	ref.imprimirProposito();
}

void datosUsuario() {
	system("cls");
	impresionTitulo(1,1);
	imprimirUsuario(usuario[usuarioActual]);
	continuar();
	menu();
}
void modificarUsuario() {
	system("cls");
	impresionTitulo(1, 2);
	cin.ignore();
	creacionUsuario(usuario[usuarioActual]);
	cout << "\nEl usuario modificado tiene las siguientes caracteristicas : " << endl;
	imprimirUsuario(usuario[usuarioActual]);
	continuar();
	menu();
}

void agregarUsuario() {
	system("cls");
	impresionTitulo(1, 3);
	numeroUsuarios++;
	cin.ignore();
	creacionUsuario(usuario[numeroUsuarios]);
	cout << "\nEl usuario creado tiene las siguientes caracteristicas : " << endl;
	imprimirUsuario(usuario[numeroUsuarios]);
	usuarioActual = numeroUsuarios;
	continuar();
	menu();
}

void cambiarUsuario() {
	system("cls");
	impresionTitulo(1, 4);
	cout << "Los usuarios son : " << endl;
	for (int i = 1; i <= numeroUsuarios; i++) {
		cout << i << " - ";
		usuario[i].imprimirNombre();
		cout << endl;
	}
	cout << "Ingrese su seleccion : ";
	cin >> usuarioActual;
	continuar();
	menu();
}


void metaDiaria() {
	int pasos, horas, minutos, segundos, opcion;
	double calorias;
	system("cls");
	impresionTitulo(1, 5);
	cout << "Por favor ingrese los siguentes datos : " << endl;
	cout << "Tipo de actividad a realizar : \n1 - Actividad Ligera (1 a 3 veces por semana)" << endl;
	cout << "2 - Actividad moderada (3 a 5 veces por semana)" << endl;
	cout << "3 - Actividad intensa (6 a 7 veces por semana)" << endl;
	cout << "4 - Actividad extremadamente alta (atletas profesionales)" << endl;
	cout << "5 - Ninguna" << endl;
	cin >> opcion;
	usuario[usuarioActual].asignarActividad(opcion);
	cout << "Duracion de la actividad fisica : \nHoras : ";
	cin >> horas;
	cout << "Minutos : ";
	cin >> minutos;
	cout << "Segundos : ";
	cin >> segundos;
	usuario[usuarioActual].asignarDuracionAF(horas, minutos, segundos);
	cout << "Meta calorica diaria ( " << usuario[usuarioActual].obtenerCaloriasRecom() << " kcal recomendadas ) : ";
	cin >> calorias;
	usuario[usuarioActual].asignarCaloriasRecom(calorias);
	cout << "Desea agregar conteo de pasos ? ( 1 = Si / 0 = No) ";
	cin >> pasos;
	if (pasos == 1) {
		cout << "Meta diaria de pasos : ";
		cin >> pasos;
		usuario[usuarioActual].asignarPasosMeta(pasos);
	}
	cout << "Duracion de la actividad fisica : \nHoras : ";
	cin >> horas;
	cout << "Minutos : ";
	cin >> minutos;
	cout << "Segundos : ";
	cin >> segundos;
	usuario[usuarioActual].asignarDuracionP(horas, minutos, segundos);
	continuar();
	menu();

}

void metaCalculada() {
	system("cls");
	impresionTitulo(1, 6);
	cout << "Basandonos en tu proposito de ";
	usuario[usuarioActual].imprimirProposito();
	if (usuario[usuarioActual].obtenerCondicion() != 0) {
		cout << " y tu ";
		usuario[usuarioActual].imprimirCondicion();
	}
	cout << " te recomendamos el siguente regimen de ejercicio." << endl;
	usuario[usuarioActual].calcularRegimen();
	continuar();
	menu();
}

void progresoDiario() {
	system("cls");
	impresionTitulo(1, 7);
	cout << "Tu progreso diario para cumplir con tu proposito de ";
	usuario[usuarioActual].imprimirProposito();
	cout << " es el siguiente : \n" << endl;
	cout << "Has realizado actividad fisica de tipo ";
	usuario[usuarioActual].imprimirActividad(usuario[usuarioActual].obtenerActividad());
	cout << " con una duracion de ";
	usuario[usuarioActual].imprimirDuracionAF2();
	cout << endl;
	cout << "Tu meta es realizar actividad fisica de tipo ";
	usuario[usuarioActual].imprimirActividad(usuario[usuarioActual].obtenerActividadProm());
	cout << " con una duracion de ";
	usuario[usuarioActual].imprimirDuracionAF();
	cout << endl;

	cout << "Has dado la cantidad de " << usuario[usuarioActual].obtenerPasos() << " pasos con una duracion de ";
	usuario[usuarioActual].imprimirDuracionP2();
	cout << endl;
	cout << "Tu meta es dar la cantidad de " << usuario[usuarioActual].obtenerPasosMeta() << " pasos con una duracion de ";
	usuario[usuarioActual].imprimirDuracionP();
	cout << endl;

	cout << "Has ingerido la cantidad de " << usuario[usuarioActual].obtenerCaloriasIng() << " kcal de " << usuario[usuarioActual].obtenerCaloriasRecom()
		<< " kcal recomendadas" << endl;
	cout << "Visita la opcion de recomendaciones diarias para una vista mas detallada. " << endl;
	continuar();
	menu();
}

void guardarUsuarios() {
	system("cls");
	impresionTitulo(1, 9);
	int cont;
	cout << "Se guardara un archivo con los siguentes usuarios : " << endl;
	for (int i = 1; i <= numeroUsuarios; i++) {
		cout << i << " - ";
		usuario[i].imprimirNombre();
		cout << endl;
	}
	do {
		cout << "\nIngrese 1 para continuar : ";
		cin >> cont;
	} while (cont != 1);
	FILE * users;
	int i = 1;
	double estatura, peso;
	int edad, condicion, proposito;
	char sexo;
	char nombre[50];
	errno_t err;
	err = fopen_s(&users, "C:\\Users\\Zypher\\Desktop\\usuarios.txt", "w+");
	if ( err != 0){
		cout << "\nError al guardar el archivo!";
	}
	while (i <= numeroUsuarios) {
		strcpy_s(nombre, usuario[i].obtenerNombre());
		estatura = usuario[i].obtenerEstatura();
		peso = usuario[i].obtenerPeso();
		edad = usuario[i].obtenerEdad();
		condicion = usuario[i].obtenerCondicion();
		sexo = usuario[i].obtenerSexo();
		proposito = usuario[i].obtenerProposito();
		fprintf(users, "%s %c %lf %lf %d %d %d \n", nombre, sexo, estatura, peso, edad, condicion, proposito);
		i++;
	}
	err = fclose(users);
	cout << "\nArchivo Guardado!" << endl;
	continuar();
	menu();
}

void configuaraciones() {
	system("cls");
	int pasos, horas, minutos, segundos, opcion;
	double calorias;
	impresionTitulo(1, 10);
	cout << "Ingresa los pasos dados por el usuario : ";
	cin >> pasos;
	usuario[usuarioActual].asignarPasos(pasos);
	cout << "Duracion de la actividad fisica : \nHoras : ";
	cin >> horas;
	cout << "Minutos : ";
	cin >> minutos;
	cout << "Segundos : ";
	cin >> segundos;
	usuario[usuarioActual].asignarDuracionP2(horas, minutos, segundos);
	usuario[usuarioActual].asignarCalQuemadasPasos();
	cout << "Realizo otra actividad ? (1 = Si , 0 = No) ";
	cin >> pasos;
	if (pasos == 1) {
		cout << "Duracion de la actividad fisica : \nHoras : ";
		cin >> horas;
		cout << "Minutos : ";
		cin >> minutos;
		cout << "Segundos : ";
		cin >> segundos;
		usuario[usuarioActual].asignarDuracionAF2(horas, minutos, segundos);
		cout << "Tipo de actividad realizada : \n1 - Actividad Ligera" << endl;
		cout << "2 - Actividad moderada" << endl;
		cout << "3 - Actividad intensa" << endl;
		cout << "4 - Actividad extremadamente alta" << endl;
		cin >> opcion;
		usuario[usuarioActual].asignarActividadProm(opcion);
		usuario[usuarioActual].asignarCalQuemadasAF(opcion);
	}
	cout << "Consumo de calorias hasta ahora : ";
	cin >> calorias;
	usuario[usuarioActual].asignarCaloriasIng(calorias);
	usuario[usuarioActual].calcularCalorias();
	continuar();
	menu();
}

void continuar()
{
	int salida;
	if (usuarioActual != 0) {

		do {
			cout << "\nIngrese 0 para regresar al menu : ";
			cin >> salida;
		} while (salida != 0);
	}
	else {

		do {
			cout << "\nIngrese 0 para ingresar al menu : ";
			cin >> salida;
		} while (salida != 0);
	}
}*/
#include "stdafx.h"