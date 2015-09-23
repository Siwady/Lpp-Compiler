#ifndef REALTYPE_H
#define REALTYPE_H
#include "type.h"

class RealType : public Type
{
public:
    RealType();

    // Type interface
public:
    string GetName();
};

#endif // REALTYPE_H
