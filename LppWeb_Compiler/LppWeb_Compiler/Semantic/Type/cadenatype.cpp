#include "cadenatype.h"
#include "../../Interpret/Values/cadenavalue.h"

CadenaType::CadenaType()
{
}

CadenaType::~CadenaType()
{
}

Value* CadenaType::DefaultValue()
{
	return new CadenaValue("");
}

CadenaType::CadenaType(int dim)
{
    Dim=dim;
    this->Name="Cadena";
}



string CadenaType::GetName()
{
    return Name;
}
