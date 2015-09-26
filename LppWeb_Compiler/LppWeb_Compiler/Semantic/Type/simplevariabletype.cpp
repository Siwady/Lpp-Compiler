#include "simplevariabletype.h"
#include "../../helper.h"
#include "../../Interpret/Values/enterovalue.h"
#include "../../Interpret/Values/cadenavalue.h"
#include "../../Interpret/Values/realvalue.h"
#include "../../Interpret/Values/caractervalue.h"
#include "../../Interpret/Values/booleanovalue.h"

class CadenaValue;

SimpleVariableType::~SimpleVariableType()
{
	delete OfType;
}

Value* SimpleVariableType::DefaultValue()
{
	if (Helper::ToLower(OfType->Name) == Helper::ToLower("entero"))
	{
		return new EnteroValue(0);
	}
	else if (Helper::ToLower(OfType->Name) == Helper::ToLower("cadena"))
	{
		return new CadenaValue("");
	}
	else if (Helper::ToLower(OfType->Name) == Helper::ToLower("real"))
	{
		return new RealValue(0);
	}
	else if (Helper::ToLower(OfType->Name) == Helper::ToLower("caracter"))
	{
		return new CaracterValue('\0');
	}
	else if (Helper::ToLower(OfType->Name) == Helper::ToLower("booleano"))
	{
		return new BooleanoValue(false);
	}
}

SimpleVariableType::SimpleVariableType(Type *t)
{
    this->Name="SimpleVariable";
    this->OfType=t;
}



string SimpleVariableType::GetName()
{
    return Name;
}
