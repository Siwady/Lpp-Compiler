#include "enterotype.h"
#include "../../Interpret/Values/enterovalue.h"

EnteroType::~EnteroType()
{
}

Value* EnteroType::DefaultValue()
{
	return new EnteroValue(0);
}

EnteroType::EnteroType()
{
    this->Name="Entero";
}



string EnteroType::GetName()
{
    return Name;
}
