#ifndef SIMPLEVARIABLETYPE_H
#define SIMPLEVARIABLETYPE_H
#include "type.h"

class SimpleVariableType : public Type
{
public:
    Type *OfType;
    SimpleVariableType(Type *t);

    // Type interface
public:
    string GetName();
};

#endif // SIMPLEVARIABLETYPE_H
