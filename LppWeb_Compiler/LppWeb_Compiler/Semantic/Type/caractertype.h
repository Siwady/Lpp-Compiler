#ifndef CARACTERTYPE_H
#define CARACTERTYPE_H
#include "type.h"

class CaracterType : public Type
{
public:
	~CaracterType() override;
	Value* DefaultValue() override;
	CaracterType();

    string GetName() override;
};

#endif // CARACTERTYPE_H
