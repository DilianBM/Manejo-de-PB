#ifndef TAREA_H
#define TAREA_H
#include <string>
#include <vector>
using namespace std;

class Tarea
{
public:
    Tarea();
    virtual ~Tarea();
    string nombre;
    int prioridad;
    double esfuerzo;
    int impacto;
    bool asignado=false;
    bool asignadoPB=false;

    string requerimiento;
    void agregaRelaciones(Tarea);
    void setdata(string,int,double,int);
    void eliminar_dup();
    vector<Tarea> relaciones;
    bool operator< (Tarea p);



protected:

private:
};

#endif // TAREA_H
