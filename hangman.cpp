/*Equipo: Gerardo Femat Delgado y Emmanuel Mu�oz Cerda*/

// Librerias
#include <stdio.h>
#include <string.h> //Manejo de las cadenas
#include <stdlib.h> //Aleatorizar
#include <time.h>	//Obetenr numeros
#include <conio.h>	//Usar getch para que el usuario solo pueda poner una letra
#include <ctype.h>	//Manejo de caracteres

// Constantes globales
const int PALABRAS = 10;
const int CARACTERES = 20;
const char ESPACIOS = 40;

// Prototipos
void presentacion();					   // Hace una peque�a presentacion al inicar el programa dando la bienvenida
void participantes();					   // Registra los participantes
void menu();							   // Despliega el menu de opciones
void asignacionesPalabras(char[], char[]); // Funcion que rellena los char array con las palabras que pueden salir al usuario
int aleatorios(int);					   // Funcion que obtiene numeros aleatorios para obtener la palabra que le saldra al usuario
int complejidad();						   // Le pregunta al usuario en que dificultad desea jugar, y retorna la dificultad.
int juego(char[], char[], char[]);		   // Funcion principal del juego
void imprAhorcado(int, int, int, char[]);  // Funcion que imprime la persona y manda mensajes segun la situaci�n del usuario
void imprMnsJuego(char[], char[]);		   // Funcion que imprime informacion de usuario que esta jugando y la categoria de la palabra
void imprUsadas(char[]);				   // Funcion del juego que imprime las letras que ha usado el usuario
int imprPalabra(char[], int[]);			   // Imprime la palabra que el usuario debe adivinar.
char obtenerCaracter();					   // Funcion que le pide al usuario un caracter, lo tranfrorma en mayusculas y lo regresa
bool comprobarUsadas(char[], int);		   // Funcion que comprueba si el usuario ha usado anteriormente el mismo caracter
int controlVida(int, int, int, char[]);	   // Funcion del juego que se ejecuta cuando el usuario no responde correctamente y baja la vida

// Main
int main()
{
	presentacion();
	menu();
	return 0;
}

// Implementacion
void presentacion()
{
	printf("\n^( '-' )^  Bienvenido! Vamos a Jugar Ahorcado <(' .' )>\n");
	printf("\n\t   -> Presiona Enter para empezar! <-");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n Hecho por: Gerardo Femat Delgado y Emmanuel Munoz Cerda");
	printf("\n Grupo: 1-ISC-C Generacion: 2020-2024\n PROYECTO FINAL DE LOGICA DE PROGRAMACION\n UNIVERSIDAD AUTONOMA DE AGUASCALIENTES\n");
	scanf("%c");
	system("cls");
}

void participantes(char participante[])
{
	fflush(stdin);
	bool error = true; // Declaramos esto paracomprobar que el usuario no ingrese mas espacios de los que permite el programa
	do
	{ // Es ciclico ya que si el usuario ingresa mas caracteres de los que debe, lo devuelve a pedir su nombre.
		printf("\n\n\t Nombre del participante: \n\n\t\t");
		gets(participante);
		if (strlen(participante) > ESPACIOS)
		{
			system("cls");
			printf("\n\tError! Demasiado largo, vuelva a intentarlo\n\nPresione enter para continuar...");
			scanf("%c");
			system("cls");
		}
		else
		{
			printf("\n  El participante registrado es: %s\n\t>O< EMPEZEMOS A JUAGR! >O< \n\nPresione enter para continuar...", participante);
			scanf("%c");
			system("cls");
			error = false;
		}
		fflush(stdin);
	} while (error);
}

void menu()
{
	int resp, puntos = 0; // RESP, guarda lo que quiere hacer el usuario y PUNTOS guarda la puntuacion que lleva el usuario durante el juego
	char usuario[ESPACIOS];
	char palabra[CARACTERES];	// Guarda la palabra que se le va a mostrar al ususario
	char categoria[CARACTERES]; // Guarda que categoria es la palabra
	participantes(usuario);
	do
	{ // Repite el menu hasta seleccionar la opcion de salir
		system("cls");
		printf("\n\t \t Menu de opciones\n\n");
		printf("\t Registro de participantes .... 1\n");
		printf("\t Iniciar el juego ............. 2\n");
		printf("\t Salir ........................ 3\n");
		printf("\n\t Seleccione una opcion: ");
		resp = getche();
		switch (resp)
		{
		case '1':
			participantes(usuario);
			puntos = 0; // Se reinician los puntos al cambiar de usuario
			break;
		case '2':
			system("cls");
			asignacionesPalabras(palabra, categoria);
			puntos += juego(usuario, palabra, categoria);
			printf("\n\t Llevas: %d puntos!\n\nPresiona enter para continuar...", puntos);
			scanf("%c");
			break;
		case '3':
			break;
		default:
			printf("\nERROR! Seleccione una opcion del menu\n");
			scanf("%c");
		}
		system("cls");
	} while (resp != '3');
}

void asignacionesPalabras(char palabra[], char tipo[])
{ // Asigna las palabras a cada espacio del array de las distintas categorias.
	char colores[PALABRAS][CARACTERES], frutas[PALABRAS][CARACTERES], series[PALABRAS][CARACTERES];
	int dificultad;
	strcpy(colores[0], "AZUL");
	strcpy(colores[1], "ROJO");
	strcpy(colores[2], "CAFE");
	strcpy(colores[3], "ROSA");
	strcpy(colores[4], "VERDE");
	strcpy(colores[5], "NEGRO");
	strcpy(colores[6], "BLANCO");
	strcpy(colores[7], "MAGENTA");
	strcpy(colores[8], "NARANJA");
	strcpy(colores[9], "AMARILLO");
	strcpy(frutas[0], "UVA");
	strcpy(frutas[1], "PERA");
	strcpy(frutas[2], "MANGO");
	strcpy(frutas[3], "MELON");
	strcpy(frutas[4], "SANDIA");
	strcpy(frutas[5], "CEREZA");
	strcpy(frutas[6], "GUAYABA");
	strcpy(frutas[7], "MANZANA");
	strcpy(frutas[8], "AGUACATE");
	strcpy(frutas[9], "MANDARINA");
	strcpy(series[0], "DARK");
	strcpy(series[1], "DR HOUSE");
	strcpy(series[2], "COBRA KAI");
	strcpy(series[3], "SOUTH PARK");
	strcpy(series[4], "DRAGON BALL");
	strcpy(series[5], "BOB ESPONJA");
	strcpy(series[6], "BREAKING BAD");
	strcpy(series[7], "RICK AND MORTY");
	strcpy(series[8], "STRANGER THINGS");
	strcpy(series[9], "THE WALKING DEAD");
	dificultad = complejidad();
	switch ((aleatorios(0) / 10))
	{
	case 1:
		strcpy(palabra, colores[(aleatorios(dificultad) % 10)]);
		strcpy(tipo, "Colores");
		break;
	case 2:
		strcpy(palabra, frutas[(aleatorios(dificultad) % 10)]);
		strcpy(tipo, "Frutas");
		break;
	case 3:
		strcpy(palabra, series[(aleatorios(dificultad) % 10)]);
		strcpy(tipo, "Series");
		break;
	}
}

int aleatorios(int dificultad)
{
	int num;
	srand(time(NULL));
	switch (dificultad)
	{ // Obtiene numeros aleatorios dependiendo de la dificultad que el usuario elige
	case 0:
		num = ((rand() % 30) + 10);
		break;
	case 1:
		num = (rand() % 3);
		break;
	case 2:
		num = ((rand() % 3) + 4);
		break;
	case 3:
		num = ((rand() % 3) + 7);
		break;
	}
	return num;
}

int complejidad()
{
	char res;
	int resp;
	do
	{
		fflush(stdin);
		printf("\n\t  Seleccion de dificultad\n");
		printf("\n\tFacil ................... 1");
		printf("\n\tIntermedio .............. 2");
		printf("\n\tDificil ................. 3");
		printf("\n\n\tSeleccione una dificultad: ");
		res = getch();
		switch (res)
		{
		case '1':
			resp = 1;
			break;
		case '2':
			resp = 2;
			break;
		case '3':
			resp = 3;
			break;
		default:
			resp = 0;
			printf("\n\tERROR! Seleccione una dificultad disponible\n");
			printf("Presione enter para continuar...");
			scanf("%c");
			system("cls");
		}
	} while (resp == 0);
	return resp;
}

int juego(char participante[], char palabra[], char tipo[])
{
	const int TAM = strlen(palabra);
	int comp[TAM];							  // comp Guarda las posiciones donde la letra es igual a la puesta por el usuario,
	int contUsadas = 0;						  // Cuenta cuantos caracteres se han usado
	int continuar, entraCorrec = 0, vida = 6; // entraCorrec Verifica si la entrada tuvo coincidencias
	char entrada, usadas[32] = {"\0"};
	int puntuaje = 0;
	puntuaje = TAM * 100;
	do
	{
		imprAhorcado(vida, 1, puntuaje, palabra);
		imprMnsJuego(participante, tipo);
		fflush(stdin);
		imprUsadas(usadas);
		continuar = imprPalabra(palabra, comp);
		if (continuar == TAM)
		{ // Si las palabras expuestas son iguales a los caracteres de la palabra quiere decir que el jugador ha ganado
			if (vida < 6)
			{ // Ocurre cuando el usuario comete algun error.
				imprAhorcado(vida = 7, 2, puntuaje, palabra);
			}
			else
			{ // Ocurre cuando el usuario no comete ning�n error!
				imprAhorcado(vida = 7, 3, puntuaje, palabra);
			}
			break; // Rompe el ciclo para que no se vuelva a mostrar que ingrese una palabra
		}
		do
		{											// Si el usuario introduce dos veces el mismo caracter el programa le dir� que introduzca uno nuevo
			usadas[contUsadas] = obtenerCaracter(); // Guarda la letra usada en un string para que el usuario pueda ver que letras ha usado.
		} while (comprobarUsadas(usadas, contUsadas));
		for (int i = 0; i < TAM; i++)
		{
			if (usadas[contUsadas] == palabra[i])
			{				 // Compara la entrada con cada una de los caracteres de la palabra
				comp[i] = i; // Guarda la posici�n del caracter
				entraCorrec = 1;
			}
		}
		if (entraCorrec == 0)
		{
			puntuaje -= (puntuaje / vida);
		}
		contUsadas++;
		vida = controlVida(entraCorrec, vida, puntuaje, palabra);
		entraCorrec = 0; // Reinicia el contador de entradas correctas para poder determinar si el siguiente caracter esta en la palabra
	} while (vida);		 // Busca la cantidad de vida que le queda al jugador, cuando es cero se detiene el juego.
	return puntuaje;
}

void imprAhorcado(int vidas, int estado, int puntuacion, char palabra[])
{
	system("cls");
	fflush(stdin);
	switch (vidas)
	{ // Imprime el sprite del ahorcado segun las vidas que le queden
	case 0:
		printf("\n\t_____\n\t|   6\n\t|  O|/\n\t|   |\n\t|  / \\\n\t|\n\n  NOOOOOOOOOOOO! DEBIAS AYUDARME ;(\n");
		break;
	case 1:
		printf("\n\t_____\n\t|   O\n\t|  \\|/\n\t|   |\n\t|  /\n\t|\n\n PON A FUNCIONAR EL MOTOR! QUE ME MUERO!\n");
		break;
	case 2:
		printf("\n\t_____\n\t|   O\n\t|  \\|/\n\t|   |\n\t|\n\t|\n\n   HEY ME ESTOY MURIENDO AYUDAME!\n");
		break;
	case 3:
		printf("\n\t_____\n\t|   O\n\t|  \\|\n\t|   |\n\t|\n\t|\n\n ESTA BIEN, NO TE PREOCUPES... AUN NO ;)\n");
		break;
	case 4:
		printf("\n\t_____\n\t|   O\n\t|   |\n\t|   |\n\t|\n\t|\n\n   UNO... DOS ERRORES QUE MAS DA!\n");
		break;
	case 5:
		printf("\n\t_____\n\t|   O\n\t|\n\t|\t\n\t|\n\t|\n\n RELAJADO, AUN TE QUEDAN DEMASIADOS INTENTOS\n DEBERIAS QUEMAR UNOS CUANTOS\n");
		break;
	case 6:
		printf("\n\t_____\n\t|\n\t|\n\t|\t\n\t|\n\t|\n");
		break;
	case 7:
		printf("\n\t_____\n\t|\n\t|   O\n\t|  \\|/\n\t|   |\n\t|  / \\\n\n MUCHISIMAS GRACIAS, ME SALVASTE!\n");
	}
	switch (estado)
	{ // Envia mensajes al usuario, segun como este termine el juego
	case 0:
		printf("\n\n �\(^.^)/� OOOPS! Sigue intentandolo! �\(^.^)/� \n\tLa palabra era: %s\n\tObtuviste: %d puntos\n\n", palabra, puntuacion);
		break;
	case 1:
		printf("\n\tTe quedan: %d intentos!\n", vidas);
		break;
	case 2:
		printf("\n\n\tUFFFF! Que se moria!\n");
		printf("\n\n Felicidades! Completaste la palabra: %s \n\t Obtuviste: %d puntos\n\n", palabra, puntuacion);
		break;
	case 3:
		printf("\n Te quedaban todos los intentos! Felicidades supremas!\n");
		printf("\n   Completaste la palabra: %s\n\tPuntuacion perfecta!\n\tObtuviste %d puntos\n\n", palabra, puntuacion);
		break;
	}
}

void imprMnsJuego(char participante[], char tipo[])
{
	printf("\n\t Participante: %s\n", participante);
	printf("\n La categoria de la palabra es: %s", tipo);
	printf("\n Podras adivinar la palabra? Recuerda usar espacios!\n\n");
}

void imprUsadas(char usadas[])
{
	printf(" Las letras usadas han sido: ");
	for (int i = 0; i < strlen(usadas); i++)
	{
		if (usadas[i] == ' ' || usadas[i] == 13)
		{ // Cuando el ususario escribe un espacio o un enter(13) se imprime un guion(-).
			printf("- ");
		}
		else
		{
			printf("%c ", usadas[i]);
		}
	}
	printf("\n\n");
	fflush(stdin);
}

int imprPalabra(char palabra[], int comp[])
{
	int continuar = 0;
	for (int i = 0; i < strlen(palabra); i++)
	{ // Imprime lo que ve el usuario que debe de adivinar
		if (i == 0 || i == (strlen(palabra) - 1) || i == comp[i])
		{ // Si la letra es la primera, ultima o la letra esta usada se exhibira la letra.
			printf(" %c ", palabra[i]);
			continuar++; // Suma continuar segun la cantidad de caracteres expuestos
		}
		else
		{ // En caso contrario se imprimira un gui�n bajo denotando que faltan caracteres por descubrir
			printf(" _ ");
		}
	}
	return continuar;
}

char obtenerCaracter()
{
	char entrada;
	printf("\n\nIngresa una letra: ");
	entrada = toupper(getch()); // Obtiene una letra y la vuelve mayuscula
	return entrada;
}

bool comprobarUsadas(char usadas[], int nueva)
{
	bool verificacion = false;
	int i = 0;
	fflush(stdin);
	do
	{
		if (isdigit(usadas[nueva]))
		{
			printf("\nHEY! Introduce una caracter valido (Letras)!\n");
			verificacion = true;
			break;
		}
		else
		{
			if (nueva == 0)
			{
				continue;
			}
			if (usadas[nueva] == usadas[i])
			{
				printf("\nHEY! Introduce una letra nueva!\n");
				verificacion = true;
				break;
			}
			else
			{
				verificacion = false;
			}
		}
		i++;
	} while (i != nueva);
	return verificacion;
}

int controlVida(int incorrecto, int vida, int puntuacion, char palabra[])
{
	if (incorrecto == 0)
	{
		--vida;
		if (vida == 0)
		{ // Si el ususario tiene 0 vidas quiere decir que perdio y se debe de imprimir el ahorcado completo.
			imprAhorcado(vida, 0, puntuacion, palabra);
		}
	}
	return vida;
}
