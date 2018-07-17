/*Dilian Badilla,Alberto soto
  clase Proyecto
  versión 1
  esta clase se maneja el proyecto el cual esta compuesto por los requerimientos,equipo,PB,relaciones de tareas...
*/
#include "Proyecto.h"
#include "Requerimientos.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include "Tarea.h"
#include <sstream>

using namespace std;
Proyecto::Proyecto()
{
    //ctor
}

Proyecto::~Proyecto()
{
    //dtor
}
/*
no recibe ni retorna nada y agrega las tareas de los tres requerimientos al PB
*/
void Proyecto::agregaPB()
{
    vector<Tarea>::iterator iter;
    for(iter=tecnicos.vect.begin(); iter!=tecnicos.vect.end(); iter++)//recorre el vector de tareas de requerimientos tecnicos y los mete en el PB
    {
        if(iter->asignadoPB==false)
        {
            iter->requerimiento="Tecnico";
            PB.push_back(*iter);
            iter->asignadoPB=true;
        }

    }
    vector<Tarea>::iterator itera;
    for(itera=administrativos.vect.begin(); itera!=administrativos.vect.end(); itera++)//recorre el vector de tareas de requerimientos administrativos y los mete en el PB
    {
        if(itera->asignadoPB==false)
        {
            itera->requerimiento="Administrativo";
            PB.push_back(*itera);
            itera->asignadoPB=true;
        }
    }
    vector<Tarea>::iterator iterador;
    for(iterador=funcionales.vect.begin(); iterador!=funcionales.vect.end(); iterador++)//recorre el vector de tareas de requerimientos funcionales y los mete en el PB
    {
        if(iterador->asignadoPB==false)
        {
            iterador->requerimiento="Funcional";
            PB.push_back(*iterador);
            iterador->asignadoPB=true;
        }
    }

    ordena();
}
/*
no retorna nada y modifica los atributos de una tarea
*/
void Proyecto::modificarTareas(int indiceTar,int op,string nuevoDato)
{
    if(indiceTar>=0 && indiceTar<=PB.size())
    {
        if(op==1)
        {
            PB[indiceTar].prioridad=atoi(nuevoDato.c_str());

        }
        if(op==2)
        {
            PB[indiceTar].esfuerzo=atof(nuevoDato.c_str());

        }
        if(op==3)
        {
            PB[indiceTar].impacto=atoi(nuevoDato.c_str());

        }
    }


}
/*
no recibe nada y ordena el PB y como ya se habia sobrecargado el operador
ya se sabe que una tarea es menor a otra por su prioridad y impacto
*/
void Proyecto::ordena()
{
    for (int it1=0; it1<PB.size(); it1++)
    {

        for (int it2=it1+1; it2<PB.size(); it2++)
        {
            if (PB[it1].prioridad<PB[it2].prioridad)
            {
                Tarea tmp=PB[it2];
                PB[it2]=PB[it1];
                PB[it1]=tmp;
            }
            else
            {
                if(PB[it1].prioridad==PB[it2].prioridad &&PB[it1].impacto<PB[it2].impacto)
                {

                    Tarea tmp=PB[it2];
                    PB[it2]=PB[it1];
                    PB[it1]=tmp;
                }
            }

        }
    }
}
/*
no retorna nada y recibe el nombre de la tarea a borrar
*/
void Proyecto::borraTarea(int n)
{
    vector<Tarea>::iterator ite;
    vector<Tarea>::iterator itera;
    for(itera=PB.begin(); itera!=PB.end(); itera++)
    {
        for(ite=itera->relaciones.begin(); ite!=itera->relaciones.end(); ite++)
        {
            if(ite->nombre==PB[n].nombre)
            {
                ite->nombre="";

            }
        }
    }
    if(n>=0 && n<=PB.size())
    {
        PB.erase (PB.begin()+n);
    }



}
/*
No recibe nada y retorna todas las tareas con su informacion
*/
string Proyecto::muestraTareas()
{
    ostringstream os;
    vector<Tarea>::iterator ite;
    int contador=0;
    for(ite=PB.begin(); ite!=PB.end(); ite++)
    {

        string h="";
        if(ite->asignado==true)
        {
            h="SI";
        }
        else
        {
            h="NO";
        }
        os<<contador<<":"<<"nombre: "<<ite->nombre<<" Prioridad: "<<ite->prioridad<<" Esfuerzo: "<<ite->esfuerzo<<" impacto "<<ite->impacto<<" asignado: "<<h<<" "<<ite->requerimiento<<endl;
        contador++;
    }
    return os.str();
}
/*
no retorna nada y recibe los indices de la persona y de la tarea que va a asociar a este
*/
void Proyecto::asignatarea(int indpersona,int indtarea)
{
    int op;
    double limitehoras;
    double horaspersona=0;
    vector<Tarea>::iterator iter;
    if(indtarea<=PB.size() && indpersona<=equipo.listaPersonas.size())
    {
        for(iter = equipo.listaPersonas[indpersona].v.begin(); iter != equipo.listaPersonas[indpersona].v.end(); iter++ )
        {
            horaspersona += iter->esfuerzo;

        }
        limitehoras=equipo.promedio+equipo.promedio*0.20;

        if(PB[indtarea].asignado==false)
        {

            if(horaspersona+PB[indtarea].esfuerzo<=limitehoras)
            {
                equipo.listaPersonas[indpersona].asignartarea(PB[indtarea]);
                PB[indtarea].asignado=true;
            }
            else
            {
                cout<<"Si se le asigna la tarea se va a pasar del limite. Desea asignarla de todas formas? Digite 1 si la quiere asignar o 2 si no"<<endl;
                cin>>op;

                if(op==1)
                {
                    equipo.listaPersonas[indpersona].asignartarea(PB[indtarea]);
                    PB[indtarea].asignado=true;
                }
            }
        }
        else
        {
            cout<<"Esa tarea ya esta asignada"<<endl;
        }
    }
}
/*
no retorna nada y asigna a la lista de tareas relacionadas el otro parametro que representa la tarea con la que se va a relacionar
*/
void Proyecto::asignaRelacion(int indtarea,int indtarea2)
{
    if(indtarea<PB.size() && indtarea2<PB.size() &&PB[indtarea].nombre!=PB[indtarea2].nombre)
    {
        PB[indtarea].agregaRelaciones(PB[indtarea2]);
    }
    else
    {
        cout<<"ingreso datos mal"<<endl;
    }



}

/*
no recibe ni retorna nada y muestra las relaciones asociadas con cada tarea
*/
void Proyecto::mostrarRelaciones()
{
    vector<Tarea>::iterator iter;
    int contador=0;
    for(iter=PB.begin(); iter!=PB.end(); iter++)
    {
        vector<Tarea>::iterator itera;
        if(iter->relaciones.empty()==false)
        {
            cout<<contador<<":"<<iter->nombre<<"  se relaciona con: ";
        }

        for(itera=iter->relaciones.begin(); itera!=iter->relaciones.end(); itera++)
        {
            cout<<"  "<<itera->nombre;

        }
        cout<<endl;


        contador++;
    }
}
//METODO MALO ARRREGLAR
/*
void Proyecto::listaRelaciones()
{
    ostringstream os;
    vector<Tarea>::iterator iter;
    int contador=0;
    for(iter=PB.begin(); iter!=PB.end(); iter++)
    {
        vector<Tarea>::iterator itera;
        if(iter->relaciones.empty()==false)
        {

            os<<contador<<":"<<iter->nombre<<"  se relaciona con: ";
            string h=os.str();
            rel.push_back(h);
        }

        for(itera=iter->relaciones.begin(); itera!=iter->relaciones.end(); itera++)
        {
            rel[contador]+=itera->nombre;

        }
        cout<<endl;


        contador++;
    }
    vector<string>::iterator it;
    for(it=rel.begin();it!=rel.end();it++){

      cout<<*it<<endl;
    }
}

*/

