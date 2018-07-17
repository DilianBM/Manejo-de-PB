/*Dilian Badilla,Alberto soto
  clase Equipo
  versión 1
  esta clase se agregan personas al equipo y se muestran las tareas asociadas con cada persona del equipo
*/
#include "Equipo.h"
#include "Persona.h"
#include "Tarea.h"
#include <iostream>
#include <vector>
Equipo::Equipo()
{
    //ctor
}

Equipo::~Equipo()
{
    //dtor
}
/*
no retorna nada y recibe una persona y la agrega al equipo
*/
void Equipo::agregarPersona(Persona<string> p)
{

    listaPersonas.push_back(p);
}
/*
no recibe nada y no retorna nada solo muestra las personas del equipo con sus respectivas tareas asociadas
*/
void Equipo::mostrarEquipo()
{

    vector<Persona<string> >::iterator ite;
    vector<Tarea>::iterator iter;
    int contador=0;
    for(ite=listaPersonas.begin(); ite!=listaPersonas.end(); ite++)
    {
        cout<<contador<<":"<<"nombre: "<<ite->nombre;

        if(ite->v.empty ()==false)
        {
            cout<<"  Tareas asociadas ";
        }

        for(iter=ite->v.begin(); iter!=ite->v.end(); iter++)
        {
            cout<<"  "<< iter->nombre;
        }
        cout<<endl;
        contador++;
    }
}

