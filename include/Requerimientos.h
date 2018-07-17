#ifndef REQUERIMIENTOS_H
#define REQUERIMIENTOS_H
#include <vector>
#include "Tarea.h"
#include "Equipo.h"

class Requerimientos
{
public:
    Requerimientos();
    virtual ~Requerimientos();
    vector<Tarea> vect;
    void agreguetareas(Tarea);
    int complejidad;



protected:

private:
};

#endif // REQUERIMIENTOS_H
