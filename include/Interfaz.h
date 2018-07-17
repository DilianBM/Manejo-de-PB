#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Proyecto.h"
#include <stdexcept>
class Interfaz
{
public:
    Interfaz();
    virtual ~Interfaz();

    void menu(Proyecto);
    void unafun()throw(runtime_error)
    {
        throw runtime_error("error no ingreso lo debido");
    }

protected:

private:
};

#endif // INTERFAZ_H
