#include "booleantype.h"
#include "../../Interpret/Values/booleanovalue.h"

BooleanType::~BooleanType()
{
}

Value* BooleanType::DefaultValue()
{
	return new BooleanoValue(false);
}

BooleanType::BooleanType()
{
    this->Name="Booleano";
}



string BooleanType::GetName()
{
    return Name;
}
