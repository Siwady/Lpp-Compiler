#ifndef BOOLEANTYPE_H
#define BOOLEANTYPE_H
#include "type.h"

class BooleanType : public Type
{
public:
    BooleanType();

    // Type interface
public:
    string GetName();
};

#endif // BOOLEANTYPE_H
