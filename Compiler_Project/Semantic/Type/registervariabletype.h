#ifndef REGISTERVARIABLETYPE_H
#define REGISTERVARIABLETYPE_H
#include "Semantic/Type/type.h"

class RegisterVariableType : public Type
{
public:
    Type *OfType;

    RegisterVariableType(Type *type);

    // Type interface
public:
    string GetName();
};

#endif // REGISTERVARIABLETYPE_H
