#ifndef BOOLEANTYPE_H
#define BOOLEANTYPE_H
#include "type.h"

class BooleanType : public Type
{
public:
	~BooleanType() override;
	Value* DefaultValue() override;
	BooleanType();

    string GetName() override;
};

#endif // BOOLEANTYPE_H
