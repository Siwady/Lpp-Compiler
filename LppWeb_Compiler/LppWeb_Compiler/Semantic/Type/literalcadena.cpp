#include "literalcadena.h"
#include "../../Interpret/Values/cadenavalue.h"

LiteralCadena::~LiteralCadena()
{
}

Value* LiteralCadena::DefaultValue()
{
	return new CadenaValue("");
}

LiteralCadena::LiteralCadena()
{
	this->Name = "Cadena";
}



string LiteralCadena::GetName()
{
    return Name;
}
