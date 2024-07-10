#ifndef PROYECTOESTRUCTURA_PERSONA_H
#define PROYECTOESTRUCTURA_PERSONA_H

#include <string>

using namespace std;

struct Persona {
    char usuario[100];
    string contrasena;
    int role; // role 0: admin, role 1: user
};

void initUsuarios(Persona personas[]);
string ocultarcontrasena();
int loginUsuario(Persona personas[], string usuario, string contrasena, int nPersonas);
int registrarUsuario(Persona personas[], int nPersonas);

#endif //PROYECTOESTRUCTURA_PERSONA_H
