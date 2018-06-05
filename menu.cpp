#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

struct listaS {
	int dato;
	listaS *siguiente;
};

struct cola {
	int dato;
	cola *siguiente;
};

void esconderCursor();
void SetColor(int ForgC);
void gotoxy(int, int);
void opcionesPrincipal();
void menuPrincipal();

//OPCION 1
void listaSimple();
void insertarLista(listaS *&, int);
void mostrarLista(listaS *);


//OPCION 2
void colaDinamica();
void insertarCola(cola *&, cola *&, int);
bool colaVacia(cola *);
void suprimirCola(cola *&, cola *&, int &);

int y;


int main() {
	esconderCursor();
	menuPrincipal();
	system("pause");
}

void esconderCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void SetColor(int ForgC) {
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

void gotoxy(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void opcionesPrincipal() {
	SetColor(15);
	gotoxy(50, 4);  cout << "LAB 1 (LISTA SIMPLE)";
	gotoxy(30, 5);  cout << "_____________________________________________________________";
	gotoxy(50, 6);  cout << "LAB 4 (COLA DINAMICA)";
	gotoxy(30, 7);  cout << "_____________________________________________________________";
	gotoxy(55, 8);  cout << "OPCION 3";
	gotoxy(30, 9);  cout << "_____________________________________________________________";
	gotoxy(55, 10); cout << "OPCION 4";
	gotoxy(30, 11); cout << "_____________________________________________________________";
	gotoxy(55, 12); cout << "OPCION 5";
	gotoxy(30, 13); cout << "_____________________________________________________________";
	gotoxy(55, 14); cout << "OPCION 6";
	gotoxy(30, 15); cout << "_____________________________________________________________";
	gotoxy(55, 16); cout << "OPCION 7";
	gotoxy(30, 17); cout << "_____________________________________________________________";
	gotoxy(55, 18); cout << "OPCION 8";
	gotoxy(30, 19); cout << "_____________________________________________________________";
	gotoxy(55, 20); cout << "OPCION 9";
	gotoxy(30, 21); cout << "_____________________________________________________________";
	gotoxy(55, 22); cout << "OPCION 10";
	gotoxy(30, 23); cout << "_____________________________________________________________";
	gotoxy(56, 24); cout << "SALIR";
	gotoxy(30, 25); cout << "_____________________________________________________________";

	if (y == 4) {
		SetColor(11);
		gotoxy(50, 4);  cout << "LAB 1 (LISTA SIMPLE)";
		SetColor(13);
		gotoxy(30, 5);  cout << "_____________________________________________________________";
	}
	else if (y == 6) {
		SetColor(11);
		gotoxy(50, 6);  cout << "LAB 4 (COLA DINAMICA)";
		SetColor(13);
		gotoxy(30, 7);  cout << "_____________________________________________________________";
	}
	else if (y == 8) {
		SetColor(11);
		gotoxy(55, 8);  cout << "OPCION 3";
		SetColor(13);
		gotoxy(30, 9);  cout << "_____________________________________________________________";
	}
	else if (y == 10) {
		SetColor(11);
		gotoxy(55, 10);  cout << "OPCION 4";
		SetColor(13);
		gotoxy(30, 11);  cout << "_____________________________________________________________";
	}
	else if (y == 12) {
		SetColor(11);
		gotoxy(55, 12);  cout << "OPCION 5";
		SetColor(13);
		gotoxy(30, 13);  cout << "_____________________________________________________________";
	}
	else if (y == 14) {
		SetColor(11);
		gotoxy(55, 14);  cout << "OPCION 6";
		SetColor(13);
		gotoxy(30, 15);  cout << "_____________________________________________________________";
	}
	else if (y == 16) {
		SetColor(11);
		gotoxy(55, 16);  cout << "OPCION 7";
		SetColor(13);
		gotoxy(30, 17);  cout << "_____________________________________________________________";
	}
	else if (y == 18) {
		SetColor(11);
		gotoxy(55, 18);  cout << "OPCION 8";
		SetColor(13);
		gotoxy(30, 19);  cout << "_____________________________________________________________";
	}
	else if (y == 20) {
		SetColor(11);
		gotoxy(55, 20);  cout << "OPCION 9";
		SetColor(13);
		gotoxy(30, 21);  cout << "_____________________________________________________________";
	}
	else if (y == 22) {
		SetColor(11);
		gotoxy(55, 22);  cout << "OPCION 10";
		SetColor(13);
		gotoxy(30, 23);  cout << "_____________________________________________________________";
	}
	else if (y == 24) {
		SetColor(11);
		gotoxy(56, 24);  cout << "SALIR";
		SetColor(13);
		gotoxy(30, 25);  cout << "_____________________________________________________________";
	}
}

void menuPrincipal() {
	 y = 4;
	char tecla;

	do {
		opcionesPrincipal();
		tecla = _getch();
		
		if (tecla == -32) {
			tecla = _getch();

			if (tecla == 72) { //tecla de arriba 
				if (y == 4)
					y = 24;
				else 
					y -= 2;
			}
			if (tecla == 80) { //tecla de abajo
				if (y == 24)
					y = 4;
				else
					y += 2;
			}
		}

		if (tecla == 13) { //tecla enter
			if (y == 4) {
				system("cls");
				listaSimple();
				system("cls");
			}
			else if (y == 6) {
				system("cls");
				colaDinamica();
				system("cls");
			}
			else if (y == 8) {

			}
			else if (y == 10) {

			}
			else if (y == 12) {

			}
			else if (y == 14) {

			}
			else if (y == 16) {

			}
			else if (y == 18) {

			}
			else if (y == 20) {

			}
			else if (y == 22) {

			}
			else if (y == 24) {
				break;
			}
		}
	} while (1);
}

void listaSimple() {
	listaS *lista = NULL;
	int dato;
	SetColor(13);
	gotoxy(0, 2); cout << "________________________________________________________________________________________________________________________";
	SetColor(11); gotoxy(45, 1); cout << "LISTA SIMPLEMENTE ENLAZADA LAB NO.1";
	gotoxy(10, 7); cout << "PARA SALIR DE ESTA OPCION DEL PROGRAMA DIGITE '-1' ";

	for (int i = 3; i <= 30; i++) {
		gotoxy(102, i); cout << "|";
		gotoxy(108, i); cout << "|";
	}

	do {
		gotoxy(10, 9); cout << "Digite un dato: ";
		gotoxy(28, 9); cin >> dato;
		insertarLista(lista, dato);
		mostrarLista(lista);
	} while (dato != -1);

	gotoxy(10, 20); system("pause");
}

void insertarLista(listaS *&lista, int n) {
	listaS *nuevo_nodo = new listaS();
	nuevo_nodo->dato = n;

	listaS *aux1 = lista;
	listaS *aux2 = NULL;

	while ((aux1 != NULL) && (aux1->dato < n)) {
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}

	if (lista == aux1)
		lista = nuevo_nodo;
	else
		aux2->siguiente = nuevo_nodo;

	nuevo_nodo->siguiente = aux1;
}

void mostrarLista(listaS *lista) {
	int i = 5;
	listaS *actual = new listaS();

	actual = lista;
	while (actual != NULL) {
		gotoxy(105, i + 1); cout << actual->dato;
		actual = actual->siguiente;
		i+=2;
	}
}

void colaDinamica() {
	cola *frente = NULL;
	cola *fin = NULL;
	int dato,i=17;

	SetColor(13);
	gotoxy(0, 2); cout << "________________________________________________________________________________________________________________________";
	SetColor(11); gotoxy(45, 1); cout << "COLA ENLAZADA LAB NO.2";
	gotoxy(10, 7); cout << "PARA SALIR DE ESTA OPCION DEL PROGRAMA DIGITE '-1' ";

	do {
		gotoxy(10, 9); cout << "Digite un dato: ";
		gotoxy(28, 9); cin >> dato;
		insertarCola(frente, fin, dato);
	} while (dato != -1);

	gotoxy(15, 14); cout << "MOSTRANDO COLA INSERTADA";

	while (frente != NULL) {
		suprimirCola(frente, fin, dato);

		if (frente != NULL) {
			gotoxy(i, 17); cout << dato;
		}
		i+=3;
	}
	gotoxy(14, 18); cout << "|";
	gotoxy(14, 19); cout << "frente";

	gotoxy(i-3, 18); cout << "|";
	gotoxy(i-3, 19); cout << "fin";
	gotoxy(20, 20); system("pause");
}

void insertarCola(cola *&frente, cola *&fin, int n) {
	cola *nuevo_nodo = new cola();

	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;

	if (colaVacia(frente))
		frente = nuevo_nodo;
	else
		fin->siguiente = nuevo_nodo;

	fin = nuevo_nodo;
}

bool colaVacia(cola *frente) {
	return (frente == NULL) ? true : false;
}

void suprimirCola(cola *&frente, cola *&fin, int &n) {
	n = frente->dato;
	cola *aux = frente;

	if (frente == fin) {
		frente = NULL;
		fin = NULL;
	}
	else 
		frente = frente->siguiente;
	
	delete aux;
}