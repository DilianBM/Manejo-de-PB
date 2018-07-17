/*Dilian Badilla,Alberto soto
  clase Tarea
  versión 1
  esta clase se definen los atributos de cada tarea y se agregan las tareas que tienen relscion con cierta tarea
*/
#include "Tarea.h"

Tarea::Tarea()
{
    //ctor
}

Tarea::~Tarea()
{
    //dtor
}

/*
no retorna nada y asigna datos a una tarea
*/
void Tarea::setdata(string nom,int prio,double esfuer,int impac)
{
    nombre=nom;
    prioridad=prio;
    esfuerzo=esfuer;
    impacto=impac;


}
/*
sobrecargaqa el operador < para saber si una tarea es menor que otra
tomando en cuenta la prioridad y el impacto
*/
bool Tarea::operator< (Tarea p)
{
    bool resp=false;
    if(this->prioridad < p.prioridad)
    {
        resp=true;
    }
    else
    {
        if(this->prioridad == p.prioridad && this->impacto < p.impacto)
        {
            resp=true;

        }

    }
    return resp;
}


/*
no retorna nada y recibe la tarea que va a agregar a la lista de relaciones de cada tarea
*/
void Tarea::agregaRelaciones(Tarea p)
{
    relaciones.push_back(p);
    eliminar_dup();//esto ayuda a que si el usuario asigna algo que ya habia asignado antes no aparezca duplicado
}
/*
elimina los duplicados en la lista de relaciones
*/
void Tarea::eliminar_dup()
{

    for(int i=0; i<relaciones.size(); i++)
        for(int j=i+1; j<relaciones.size(); j++)
        {
            ///Si encontramos un duplicado
            if(relaciones[i].nombre == relaciones[j].nombre)
            {

                ///Lo vamos intercambiando hasta que quede al final
                for(int k=j; k<relaciones.size(); k++)
                    swap(relaciones[k], relaciones[i+1]);
                relaciones.resize(relaciones.size()-1);

                j--;
            }
        }
}


