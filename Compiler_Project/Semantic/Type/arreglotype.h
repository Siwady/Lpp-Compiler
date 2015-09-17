#ifndef ARREGLOTYPE_H
#define ARREGLOTYPE_H
#include "type.h"
#include <list>
using namespace std;

class ArregloType : public Type
{
public:
    Type *ArrayType;
    list<int>* Dimention;
    ArregloType(Type *type, list<int>* dim);
    ArregloType();

    // Type interface
public:
    string GetName();
};

#endif // ARREGLOTYPE_H
