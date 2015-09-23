#ifndef CARACTERTYPE_H
#define CARACTERTYPE_H
#include "type.h"

class CaracterType : public Type
{
public:
    CaracterType();

    // Type interface
public:
    string GetName();
};

#endif // CARACTERTYPE_H
