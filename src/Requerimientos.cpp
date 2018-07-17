/*Dilian Badilla,Alberto soto
  clase Requerimientos
  versión 1
  esta clase agrega las tareas asociadas al requerimiento y define la complejidad del requerimiento
*/
#include "Requerimientos.h"
#include <vector>
Requerimientos::Requerimientos()
{
    //ctor
}

Requerimientos::~Requerimientos()
{
    //dtor
}
/*
no retorna nada y agrega las tareas a cada requerimiento
*/
void Requerimientos::agreguetareas(Tarea h)
{
    vect.push_back(h);
    complejidad +=h.esfuerzo;

}
