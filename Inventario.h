#ifndef PROYECTOESTRUCTURA_INVENTARIO_H
#define PROYECTOESTRUCTURA_INVENTARIO_H

#include "Persona.h"

using namespace std;

struct Bebida{
	int ID;
	char nombre[100];
	float costo;
	int cantidad;
	int ml;
};

struct Snack{
	int ID;
	char nombre[100];
	float costo;
	int cantidad;
};

struct Abarrote{
	int ID;
	char nombre[100];
	float costo;
	int cantidad;
};

pair<int, int> initBebidas(Bebida bebidas[], int nBebidas, int idMaxBebidas, FILE *inventario);
pair<int, int> initSnacks(Snack snacks[], int nSnacks, int idMaxSnacks, FILE *inventario);
pair<int, int> initAbarrotes(Abarrote abarrotes[], int nAbarrotes, int idMaxAbarrotes, FILE *inventario);

//mostrar 
void mostrarBebidas(Bebida bebidas[], int nBebidas);
void mostrarSnacks(Snack snacks[], int nSnacks);
void mostrarAbarrotes(Abarrote abarrotes[], int nAbarrotes);

//insertar 
pair<int, int> insertarBebida(Bebida bebidas[], int nBebidas, int idMaxBebidas);
pair<int, int> insertarSnack(Snack snacks[], int nSnacks, int idMaxSnacks);
pair<int, int> insertarAbarrote(Abarrote abarrotes[], int nAbarrotes, int idMaxAbarrotes);

//buscar
void buscarBebidas(Bebida bebidas[], int nBebidas);
void buscarSnacks(Snack snacks[], int nSnacks);
void buscarAbarrotes(Abarrote abarrotes[], int nAbarrotes);

//actualizar
void actualizarBebida(Bebida bebidas[], int nBebidas);
void actualizarSnack(Snack snacks[], int nSnacks);
void actualizarAbarrote(Abarrote abarrotes[], int nAbarrotes);

//eliminar
int eliminarBebida(Bebida bebidas[], int nBebidas);
int eliminarSnack(Snack snacks[], int nSnacks);
int eliminarAbarrote(Abarrote abarrotes[], int nAbarrotes);

bool continuarModificar();

//ordenamiento
void ordenamientoBebidas(Bebida bebidas[], int nBebidas);
void ordenamientoSnacks(Snack snacks[], int nSnacks);
void ordenamientoAbarrotes(Abarrote abarrotes[], int nAbarrotes);

void guardarInventario(Bebida bebidas[], int nBebidas, Snack snacks[], int nSnacks, Abarrote abarrotes[], int nAbarrotes, Persona Personas[], int nPersonas);

#endif //PROYECTOESTRUCTURA_INVENTARIO_H
