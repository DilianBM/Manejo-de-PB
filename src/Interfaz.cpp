/*Dilian Badilla,Alberto soto
  clase Interfaz
  versión 1
  esta clase se ejecuta un menu para que el usuario defina su proyecto y se llaman a todos los metodos a ejecucion
*/
#include "Interfaz.h"
#include "Requerimientos.h"
#include "Proyecto.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <new>
#include <ctype.h>
#include <stdexcept>
#include <exception>
#include <iostream>

/*class runtime_error : public exception {
  public:
  explicit runtime_error (const string& what_arg);
};*/
using namespace std;
Interfaz::Interfaz()
{
    //ctor
}

Interfaz::~Interfaz()
{
    //dtor
}

void Interfaz::menu(Proyecto prue)
{
    int indiceRel;
    int termine;
    string seguir;
    Persona<string> p;

    cout<<p.nombre;
    string nombrePersona;
    string nombreTarea;
    int prioridad;
    double esfuerzo;
    int impacto;
    Equipo equi;

    int indice;
    int op;
    string nuevoValor;
    char nombreentrada;


    cout << "Ingrese la opcion que desea ejecutar: \n 1.Definir equipo. \n 2.Definir tareas del requerimiento tecnico. \n 3.Definir tareas del requerimiento administrativo. \n 4.Definir tareas del requerimiento funcional. \n 5.Asignar tarea. \n 6.Mostrar las personas del equipo con sus tareas asignadas. \n 7.Para relacionar tareas(SOLO PUEDE RELACIONAR SI YA EXISTEN TAREAS).\n 8.Eliminar tareas. \n 9.Modificar tareas. \n 10.Ver PB \n 11.Mostrar Relaciones de Tareas\n 12.Salir.";
    string numero;
    cout<<"\n"<<endl;
    cin >>numero;

    int opcion=atoi(numero.c_str());
    Persona<string> persona;
    Tarea *tarea;
    int horas;
    string entrada;
    int tar;

    string nuevovalor;
    while(opcion!=13)
    {
        switch (opcion)
        {
        case 1:

            termine=-1;

            cout<<"Ingrese el promedio de horas de trabajo para este equipo:(EN FORMA NUMERICA)"<<endl;
            cin>>entrada;
            cin.ignore();
            cin.clear();
            horas=atoi(entrada.c_str());
            prue.equipo.promedio=horas;
            while(termine!=1)
            {

                cout << "Ingrese el nombre y el apellido del integrante sin espacio y presione enter."<<endl;
                cin>>entrada;
                persona.nombre=entrada;
                prue.equipo.agregarPersona(persona);

                cout<<"Si desea agregar mas personas digite 0, de lo contrario digite 1"<<endl;
                cin>>seguir;
                termine =atoi(seguir.c_str());
            }

            menu(prue);
            break;

        case 2:

            while(termine!=1)
            {
                cout << "Ingrese el nombre de la tarea."<<endl;
                cin>>nombreTarea;

                cout << "Ingrese la prioridad de la tarea (1, 2, 3...)(ENTRE MAYOR ES EL NUMERO MAYOR ES LA PRIORIDAD)."<<endl;
                cin>>entrada;
                prioridad=atoi(entrada.c_str());


                cout << "Ingrese el esfuerzo de la tarea (horas)."<<endl;
                cin>>entrada;
                esfuerzo=atof(entrada.c_str());

                cout << "Ingrese el impacto la tarea (1 impacto bajo, 2 impacto medio, 3 impacto alto)."<<endl;
                cin>>entrada;
                impacto=atoi(entrada.c_str());


                tarea = new Tarea();
                tarea->setdata(nombreTarea, prioridad, esfuerzo, impacto);
                prue.tecnicos.agreguetareas(*tarea);



                cout<<"Si desea agregar mas tareas digite 0, de lo contrario digite 1"<<endl;
                cin>>seguir;
                termine =atoi(seguir.c_str());
            }

            menu(prue);
            break;

        case 3:


            while(termine!=1)
            {
                cout << "Ingrese el nombre de la tarea."<<endl;
                cin>>nombreTarea;

                cout << "Ingrese la prioridad de la tarea (1, 2, 3...)(ENTRE MAYOR ES EL NUMERO MAYOR ES LA PRIORIDAD)."<<endl;
                cin>>entrada;
                prioridad=atoi(entrada.c_str());

                cout << "Ingrese el esfuerzo de la tarea (horas)."<<endl;
                cin>>entrada;
                esfuerzo=atof(entrada.c_str());

                cout << "Ingrese el impacto la tarea(1 impacto bajo, 2 impacto medio, 3 impacto alto)."<<endl;
                cin>>entrada;
                impacto=atoi(entrada.c_str());


                tarea = new Tarea();
                tarea->setdata(nombreTarea, prioridad, esfuerzo, impacto);
                prue.administrativos.agreguetareas(*tarea);



                cout<<"Si desea agregar mas tareas digite 0, de lo contrario digite 1"<<endl;
                cin>>seguir;
                termine =atoi(seguir.c_str());
            }

            menu(prue);
            break;

        case 4:



            while(termine!=1)
            {
                cout << "Ingrese el nombre de la tarea."<<endl;
                cin>>nombreTarea;

                cout << "Ingrese la prioridad de la tarea (1, 2, 3...)(ENTRE MAYOR ES EL NUMERO MAYOR ES LA PRIORIDAD)."<<endl;
                cin>>entrada;
                prioridad=atoi(entrada.c_str());

                cout << "Ingrese el esfuerzo de la tarea (horas)."<<endl;
                cin>>entrada;
                esfuerzo=atof(entrada.c_str());

                cout << "Ingrese el impacto la tarea(1 impacto bajo, 2 impacto medio, 3 impacto alto)."<<endl;
                cin>>impacto;
                impacto=atoi(entrada.c_str());


                tarea = new Tarea();
                tarea->setdata(nombreTarea, prioridad, esfuerzo, impacto);
                prue.funcionales.agreguetareas(*tarea);


                cout<<"Si desea agregar mas tareas digite 0, de lo contrario digite 1"<<endl;
                cin>>seguir;
                termine =atoi(seguir.c_str());
            }

            menu(prue);
            break;

        case 5:
            int indiceTareas;
            int indicePersonas;
            prue.agregaPB();
            cout<<"PB: "<<"\n"<<prue.muestraTareas()<<endl;
            cout << "Ingrese el indice de la tarea que desea asignar."<<endl;
            cin>>entrada;
            indiceTareas=atoi(entrada.c_str());


            prue.equipo.mostrarEquipo();
            cout << "Ingrese el indice de la persona a la cual le desea asignar la tarea."<<endl;
            cin>>entrada;
            indicePersonas=atoi(entrada.c_str());



            prue.asignatarea(indicePersonas, indiceTareas);

            menu(prue);
            break;

        case 6:
            prue.equipo.mostrarEquipo();
            menu(prue);
            cout<<endl;
            break;

        case 7:
            int indiceTarea1;
            int indiceTarea2;
            prue.agregaPB();
            if(prue.PB.size()>0)
            {
                cout<<"PB: "<<"\n"<<prue.muestraTareas()<<endl;
                cout << "Ingrese el indice de la tarea que desea relacionar."<<endl;
                cin>>entrada;
                indiceTarea1=atoi(entrada.c_str());
                cout << "Ingrese el indice de la tarea que desea relacionar con la primera tarea:."<<endl;
                cin>>entrada;
                indiceTarea2=atoi(entrada.c_str());
                prue.asignaRelacion(indiceTarea1,indiceTarea2);

            }
            menu(prue);
            break;

        case 8:
            prue.agregaPB();
            cout<<"PB: "<<"\n"<<prue.muestraTareas()<<endl;
            cout<<"Ingrese el indice de la tarea a borrar"<<endl;
            cin>>tar;
            cin.ignore();
            cin.clear();
            prue.borraTarea(tar);
            cout<<"\n"<<endl;
            menu(prue);
            break;
        case 9:
            prue.agregaPB();
            cout<<"PB: "<<"\n"<<prue.muestraTareas()<<endl;
            cout<<"Ingrese el indice de la tarea que desea modificar."<<endl;
            cin>>indice;
            cout<<"Ingrese 1 para prioridad, 2 para esfuerzo y 3 para impacto ."<<endl;
            cin>>op;
            cout<<"Ingrese el nuevo valor"<<endl;
            cin>>nuevoValor;
            prue.modificarTareas(indice, op, nuevoValor);
            menu(prue);
            break;
        case 10:
            prue.agregaPB();
            cout<<"PB: "<<"\n"<<prue.muestraTareas()<<endl;
            menu(prue);
            break;

        case 11:
            prue.mostrarRelaciones();
            menu(prue);
            break;
        case 12:
            opcion=13;

        default :

            exit(0);

        }
    }
}
