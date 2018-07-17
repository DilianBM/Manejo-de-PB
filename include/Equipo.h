#ifndef EQUIPO_H
#define EQUIPO_H
#include "Persona.h"
#include <Vector>

class Equipo
{
public:
    Equipo();
    virtual ~Equipo();
    vector <Persona<string>> listaPersonas;
    int promedio;
    void agregarPersona(Persona<string>);
    void mostrarEquipo();


protected:

private:
};

#endif // EQUIPO_H

