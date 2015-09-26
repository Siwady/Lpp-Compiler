#ifndef LITERALCADENA_H
#define LITERALCADENA_H
#include "type.h"

class LiteralCadena : public Type
{
public:
	~LiteralCadena() override;
	Value* DefaultValue() override;
	LiteralCadena();

    string GetName() override;
};

#endif // LITERALCADENA_H
