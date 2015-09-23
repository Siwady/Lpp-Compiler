#include "registervariabletype.h"

RegisterVariableType::RegisterVariableType(list<DeclareVariableNode *> *atr)
{
    this->Name="RegisterVariable";
    this->Attributes=atr;
}



string RegisterVariableType::GetName()
{
    return Name;
}
