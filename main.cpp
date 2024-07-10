#include <iostream>
#include <locale.h>
#include <wchar.h>
#include "Persona.h"
#include "funciones.h"
#include "Inventario.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "es_ES.UTF-8");
	system("chcp 65001 > null");
	system("COLOR F1");

	Bebida bebidas[999];
	Snack snacks[999];
	Abarrote abarrotes[999];
	int nBebidas = 0;
	int idMaxBebidas = 0;
	int nSnacks = 0;
	int idMaxSnacks = 0;
	int nAbarrotes = 0;
	int idMaxAbarrotes = 0;

	Persona usuarios[999];
	int nPersonas = 5;
	string usuario, contrasena;

	int opcionLogin, opcionInv, opcionUsos, usu;
	bool continuarInv, continuarMenu;
	int maxintentos = 3;
	int intentos = 0;

	initUsuarios(usuarios);
	
	pair<int, int> resultInit;
	
	FILE *inventario = fopen("inventario.csv", "r");
    
    char linea[5000];
    
    while (fgets(linea, sizeof(linea), inventario)) {
    	if (strcmp(linea, "Bebidas;;;;\n") == 0) {
    		resultInit = initBebidas(bebidas, nBebidas, idMaxBebidas, inventario);
            nBebidas = resultInit.first;
            idMaxBebidas = resultInit.second;
        } else if (strcmp(linea, "Snacks;;;;\n") == 0) {
        	resultInit = initSnacks(snacks, nSnacks, idMaxSnacks, inventario);
            nSnacks = resultInit.first;
            idMaxSnacks = resultInit.second;
        } else if (strcmp(linea, "Abarrotes;;;;\n") == 0) {
        	resultInit = initAbarrotes(abarrotes, nAbarrotes, idMaxAbarrotes, inventario);
            nAbarrotes = resultInit.first;
            idMaxAbarrotes = resultInit.second;
        }
	}
	
	fclose(inventario);
	
	do{
		opcionLogin = menulogin();
		limpiar();
		switch (opcionLogin){
		case 1:
			usu = loginUsuario(usuarios, usuario, contrasena, nPersonas);
			limpiar();
			
			if (usu != -1 && (usuarios[usu].role == 1 || usuarios[usu].role == 0)){
				intentos = 0;
				system("title Inventario Cpp");
				
				do{
					opcionInv = menuinvs(usuarios, usu);
					limpiar();
					
					pair<int, int> resultInsertar;
					
					switch (opcionInv){
						case 1:
							continuarInv = true;
							system("title Bebidas");
							
							do{
								if(usuarios[usu].role == 0){
									opcionUsos = menuusosAdm();
								} else if (usuarios[usu].role == 1){
									opcionUsos = menuusosEmp();
								}
									
								limpiar();
								
								switch(opcionUsos){
									case 1:
										mostrarBebidas(bebidas, nBebidas);
										continuarMenu = true;
										break;
									case 2:
										resultInsertar = insertarBebida(bebidas, nBebidas, idMaxBebidas);
										nBebidas = resultInsertar.first;
										idMaxBebidas = resultInsertar.second;
										continuarMenu = true;
										break;
									case 3:
										ordenamientoBebidas(bebidas, nBebidas);
										buscarBebidas(bebidas, nBebidas);
										continuarMenu = true;
										break;
									case 4:
										actualizarBebida(bebidas, nBebidas);
										continuarMenu = true;
										break;
									case 5:
										nBebidas = eliminarBebida(bebidas, nBebidas);
										ordenamientoBebidas(bebidas, nBebidas);
										continuarMenu = true;
										break;
									case 6:
										continuarMenu = false;
										break;
									default:
										opcioninvalida(opcionLogin);
										gotoxy(41,13);
										cout<<"----------Opcion invalida---------"<<endl;
										retrasar();
										limpiar();
										continuarMenu = true;
										break;
								}
							}while(continuarMenu);
							
							break;
						case 2:
							continuarInv = true;
							system("title Snacks");
							
							do{
								if(usuarios[usu].role == 0){
									opcionUsos = menuusosAdm();
								} else if (usuarios[usu].role == 1){
									opcionUsos = menuusosEmp();
								}
								limpiar();
								
								switch(opcionUsos){
									case 1:
										mostrarSnacks(snacks, nSnacks);
										continuarMenu = true;
										break;
									case 2:
										resultInsertar = insertarSnack(snacks, nSnacks, idMaxSnacks);
										nSnacks = resultInsertar.first;
										idMaxSnacks = resultInsertar.second;
										continuarMenu = true;
										break;
									case 3:
										ordenamientoSnacks(snacks, nSnacks);
										buscarSnacks(snacks, nSnacks);
										continuarMenu = true;
										break;
									case 4:
										actualizarSnack(snacks, nSnacks);
										continuarMenu = true;
										break;
									case 5:
										nSnacks = eliminarSnack(snacks, nSnacks);
										ordenamientoSnacks(snacks, nSnacks);
										continuarMenu = true;
										break;
									case 6:
										continuarMenu = false;
										break;
									default:
										opcioninvalida(opcionLogin);
										gotoxy(41,13);
										cout<<"----------Opcion invalida---------"<<endl;
										retrasar();
										limpiar();
										continuarMenu = true;
										break;
								}
							}while(continuarMenu);
							
							break;
						case 3:
							continuarInv = true;
							system("title Abarrotes");
							
							do{
								if(usuarios[usu].role == 0){
									opcionUsos = menuusosAdm();
								} else if (usuarios[usu].role == 1){
									opcionUsos = menuusosEmp();
								}
								limpiar();
								
								switch(opcionUsos){
									case 1:
										mostrarAbarrotes(abarrotes, nAbarrotes);
										continuarMenu = true;
										break;
									case 2:
										resultInsertar = insertarAbarrote(abarrotes, nAbarrotes, idMaxAbarrotes);
										nAbarrotes = resultInsertar.first;
										idMaxAbarrotes = resultInsertar.second;
										continuarMenu = true;
										break;
									case 3:
										ordenamientoAbarrotes(abarrotes, nAbarrotes);
										buscarAbarrotes(abarrotes, nAbarrotes);
										continuarMenu = true;
										break;
									case 4:
										actualizarAbarrote(abarrotes, nAbarrotes);
										continuarMenu = true;
										break;
									case 5:
										nAbarrotes = eliminarAbarrote(abarrotes, nAbarrotes);
										ordenamientoAbarrotes(abarrotes, nAbarrotes);
										continuarMenu = true;
										break;
									case 6:
										continuarMenu = false;
										break;
									default:
										opcioninvalida(opcionLogin);
										gotoxy(41,13);
										cout<<"----------Opcion invalida---------"<<endl;
										retrasar();
										limpiar();
										continuarMenu = true;
										break;
								}
							}while(continuarMenu);
							
							break;
						case 4:
							guardarInventario(bebidas, nBebidas, snacks, nSnacks, abarrotes, nAbarrotes, usuarios, nPersonas);
							continuarInv = false;
							break;
						default:
							opcioninvalida(opcionLogin);
							gotoxy(41,13);
							cout<<"----------Opcion invalida---------"<<endl;
							retrasar();
							limpiar();
							continuarInv = true;
							break;
					}
				}while(continuarInv);
				
			}else{
				limpiar();
				intentos++;
				gotoxy(42,12);
				cout << "Usuario o contrasena incorrectos." << endl;
				gotoxy(48,13);
				cout << "Te quedan " << maxintentos - intentos << " intentos." << endl;
				retrasar();
				limpiar();
			}
			
			break;

		case 2:
			nPersonas = registrarUsuario(usuarios, nPersonas);
			limpiar();
			break;
		case 3:
			guardarInventario(bebidas, nBebidas, snacks, nSnacks, abarrotes, nAbarrotes, usuarios, nPersonas);
			cout << "Saliendo..." << endl;
			return 0;
		default:
			limpiar();
			opcioninvalida(opcionLogin);
			gotoxy(41,13);
			cout<<"----------Opcion invalida---------"<<endl;
			retrasar();
			limpiar();
			break;
		}
	} while (intentos < maxintentos);

	return 0;
}
