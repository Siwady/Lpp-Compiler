#include "arreglotype.h"
#include "../../Interpret/Values/arreglovalue.h"

ArregloType::~ArregloType()
{
	delete ArrayType;
}

Value* ArregloType::DefaultValue()
{
	return new ArregloValue();
}

ArregloType::ArregloType(Type* type, list<int> *dim)
{
    this->ArrayType=type;
    this->Dimention=dim;
    this->Name="Arreglo";
}

ArregloType::ArregloType()
{
}


string ArregloType::GetName()
{
    return Name;
}
