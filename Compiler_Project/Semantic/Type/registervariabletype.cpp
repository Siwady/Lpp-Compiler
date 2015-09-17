#include "registervariabletype.h"

RegisterVariableType::RegisterVariableType(Type *type)
{
    this->Name="RegisterVariable";
    this->OfType=type;
}



string RegisterVariableType::GetName()
{
    return Name;
}
