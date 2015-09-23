#include "arreglotype.h"

ArregloType::ArregloType(Type* type, list<int> *dim)
{
    this->ArrayType=type;
    this->Dimention=dim;
    this->Name="Arreglo";
}



string ArregloType::GetName()
{
    return Name;
}
