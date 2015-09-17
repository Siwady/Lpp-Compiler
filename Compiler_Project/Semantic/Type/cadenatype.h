#ifndef CADENATYPE_H
#define CADENATYPE_H
#include "type.h"
#include <list>
using namespace std;

class CadenaType : public Type
{
public:
    int Dim;
    CadenaType(int dim);
    CadenaType();

    // Type interface
public:
    string GetName();
};

#endif // CADENATYPE_H
