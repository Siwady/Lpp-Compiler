#ifndef SIMPLEVARIABLETYPE_H
#define SIMPLEVARIABLETYPE_H
#include "type.h"

class SimpleVariableType : public Type
{
public:
	~SimpleVariableType() override;
	Value* DefaultValue() override;
	Type *OfType;
    SimpleVariableType(Type *t);

    string GetName() override;
};

#endif // SIMPLEVARIABLETYPE_H
