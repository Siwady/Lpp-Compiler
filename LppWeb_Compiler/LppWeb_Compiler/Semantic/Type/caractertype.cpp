#include "caractertype.h"
#include "../../Interpret/Values/caractervalue.h"

CaracterType::~CaracterType()
{
}

Value* CaracterType::DefaultValue()
{
	return new CaracterValue('\0');
}

CaracterType::CaracterType()
{
    this->Name="Caracter";
}



string CaracterType::GetName()
{
    return Name;
}
