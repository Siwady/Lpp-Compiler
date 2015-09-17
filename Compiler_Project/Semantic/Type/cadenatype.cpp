#include "cadenatype.h"

CadenaType::CadenaType(int dim)
{
    Dim=dim;
    this->Name="Cadena";
}



string CadenaType::GetName()
{
    return Name;
}
