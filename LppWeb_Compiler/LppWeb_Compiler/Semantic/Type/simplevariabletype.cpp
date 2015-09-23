#include "simplevariabletype.h"

SimpleVariableType::SimpleVariableType(Type *t)
{
    this->Name="SimpleVariable";
    this->OfType=t;
}



string SimpleVariableType::GetName()
{
    return Name;
}
