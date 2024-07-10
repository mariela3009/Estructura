#include "funciones.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <limits>

using namespace std;

void limpiar() {
	system("CLS");
}

void retrasar(){
    sleep(1);
}

void opcioninvalida(int opcion){
	while(true){
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}else{
			break;
		}
	}
}

int menulogin() {
    system("title Inventario Cpp");
    int option;
    gotoxy(42,10);
    cout << "--------------------------------" <<endl;
    gotoxy(45,11);
    cout << "1. Iniciar sesion" << endl;
    gotoxy(45,12);
    cout << "2. Registrar nuevo usuario" << endl;
    gotoxy(45,13);
    cout << "3. Salir" << endl;
    gotoxy(42,14);
    cout << "--------------------------------" <<endl;
    gotoxy(45,15);
    cout << "Ingrese una opción : ";
    cin >> option;

    return option;
}

int menuinvs(Persona usuarios[], int numdUsu) {
	int option;
	gotoxy(52,10);
    cout << "¡BIENVENID@ " << usuarios[numdUsu].usuario << "!" << endl;
    gotoxy(32,11);
    cout << "------------------------------------------------------------" <<endl;
    gotoxy(34,12);
    cout << "Seleccione el inventario que desea modificar o usar: " << endl;
    gotoxy(34,13);
    cout << "1) Bebidas" << endl;
    gotoxy(34,14);
    cout << "2) Snacks" << endl;
    gotoxy(34,15);
    cout << "3) Abarrotes" << endl;
    gotoxy(34,16);
    cout << "4) Guardar y salir" << endl;
    gotoxy(32,17);
    cout << "------------------------------------------------------------" <<endl;
    gotoxy(34,18);
    cout << "Ingrese una opción: ";
    
    cin >> option;
    return option;
}

int menuusosAdm() {
    int option;
    gotoxy(58,10);
    cout << "MENÚ" << endl;
    gotoxy(46,11);
    cout << "---------------------------" <<endl;
    gotoxy(50,12);
    cout << "1) Mostrar" << endl;
    gotoxy(50,13);
    cout << "2) Insertar" << endl;
    gotoxy(50,14);
    cout << "3) Buscar" << endl;
    gotoxy(50,15);
    cout << "4) Actualizar" << endl;
    gotoxy(50,16);
    cout << "5) Eliminar" << endl;
    gotoxy(50,17);
    cout << "6) Regresar" << endl;
	gotoxy(46,18);
    cout << "---------------------------" <<endl;
    gotoxy(50,19);
    cout << "Ingrese una opción: ";
    cin >> option;
    return option;
}

int menuusosEmp(){
    int option;
    gotoxy(58,11);
    cout << "MENÚ" << endl;
    gotoxy(46,12);
    cout << "---------------------------" <<endl;
    gotoxy(50,13);
    cout << "1) Mostrar" << endl;
    gotoxy(50,14);
    cout << "2) Buscar" << endl;
    gotoxy(50,15);
    cout << "3) Regresar" << endl;
    gotoxy(46,16);
    cout << "---------------------------" <<endl;
    gotoxy(50,17);
    cout << "Ingrese una opción: ";
    cin >> option;
    if(option == 1){
		option = 1;
	} else if(option == 2){
		option = 3;
	} else if(option == 3){
		option = 6;
	} else {
		option = 6;
	}
    return option;
}

void gotoxy(int x, int y){
	HANDLE Manipulador;
	COORD Coordenadas;
	Manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
	Coordenadas.X = x;  
    Coordenadas.Y = y;
	SetConsoleCursorPosition(Manipulador, Coordenadas);
}
