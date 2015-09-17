#ifndef LITERALCADENA_H
#define LITERALCADENA_H
#include "type.h"

class LiteralCadena : public Type
{
public:
    LiteralCadena();

    // Type interface
public:
    string GetName();
};

#endif // LITERALCADENA_H
