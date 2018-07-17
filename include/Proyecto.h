#ifndef PROYECTO_H
#define PROYECTO_H
#include <vector>
#include "Requerimientos.h"
#include "Tarea.h"

class Proyecto
{
public:
    Proyecto();
    virtual ~Proyecto();
    void agregaPB();
    void ordena();
    string muestraTareas();
    void asignatarea(int,int);
    void asignaRelacion(int indtarea,int indtarea2);
    void mostrarRelaciones();
    void borraTarea(int);
    void modificarTareas(int indicetarea,int op,string nuevodato);
    void listaRelaciones();

    Equipo equipo;
    Requerimientos tecnicos;
    Requerimientos administrativos;
    Requerimientos funcionales;
    vector<Tarea> PB;
    vector<string>rel;





protected:

private:
};

#endif // PROYECTO_H
