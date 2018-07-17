#ifndef PERSONA_H
#define PERSONA_H
#include <vector>
#include "Tarea.h"

template <class T>
class Persona
{
public:

    Persona() {}
    virtual ~Persona() {}
    void setnom(T n)
    {
        nombre=n;
    }

    T nombre;
    vector<Tarea> v;
    void asignartarea(Tarea t)
    {
        v.push_back(t);

    }
protected:

private:
};


#endif // PERSONA_H
