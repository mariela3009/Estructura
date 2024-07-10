#include <iostream>
#include <string>
#include <conio.h>
#include "Persona.h"
#include "funciones.h"

using namespace std;

void initUsuarios(Persona personas[]) {
	strcpy(personas[0].usuario, "Andre");
    personas[0].contrasena = "andre";
    personas[0].role = 1;
    strcpy(personas[1].usuario, "Marymar");
    personas[1].contrasena = "marymar";
    personas[1].role = 1;
    strcpy(personas[2].usuario, "Fatima");
    personas[2].contrasena = "fatima";
    personas[2].role = 1;
    strcpy(personas[3].usuario, "Mariela");
    personas[3].contrasena = "mariela";
    personas[3].role = 1;
    strcpy(personas[4].usuario, "Haydee");
    personas[4].contrasena = "haydee";
    personas[4].role = 0;
}

string ocultarcontrasena(){
	string contrasenaTemporal;
	char caracter;
	do {
		caracter = _getch();
	    if (caracter == 13) {
	      break;
	    } else if (caracter == 8){
	    	if(!contrasenaTemporal.empty()){
	    		contrasenaTemporal.pop_back();
	    		cout << "\b \b";
			}
		} else {
			contrasenaTemporal += caracter;
			cout << "*";
		}
	} while (true);
	return contrasenaTemporal;
}

int loginUsuario(Persona usuarios[], string usuario, string contrasena, int nUsuarios) {
	system("title Login");
	gotoxy(45,12);
	cout << "¡Recuerda que tienes 3 intentos!" << endl;
	gotoxy(40,13);
	cout << "-----------------------------------------" <<endl;
	gotoxy(42,14);
	cout << "Ingresa tu nombre de usuario: ";
	cin >> usuario;
	gotoxy(42,15);
	cout << "Ingresa tu contraseña: ";
	contrasena = ocultarcontrasena();
	
	for (int i = 0; i < nUsuarios; i++) {
		if (usuarios[i].usuario == usuario && usuarios[i].contrasena == contrasena) {
		    return i;
		}
	}
	return -1;
}



int registrarUsuario(Persona personas[], int nPersonas){
	system("title Nuevo Usuario");
	gotoxy(40,12);
	cout << "------------------------------------" <<endl;
	gotoxy(40,15);
	cout << "------------------------------------" <<endl;
	gotoxy(44,13);
	cout << "Ingrese el usuario: ";
	cin.ignore();
	cin.getline(personas[nPersonas].usuario, 100);

    for (int i = 0; i < strlen(personas[nPersonas].usuario); i++) {
        if (personas[nPersonas].usuario[i] == ' ') {
            personas[nPersonas].usuario[i] = '-';
        }
    }
    
	gotoxy(44,14);
	cout << "Ingrese la contraseña: ";
	personas[nPersonas].contrasena = ocultarcontrasena();
	personas[nPersonas].role = 1;
	return nPersonas+1;
}
