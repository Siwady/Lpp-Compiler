#include "registervariabletype.h"

RegisterVariableType::~RegisterVariableType()
{
}

Value* RegisterVariableType::DefaultValue()
{
	return new Value();
}

RegisterVariableType::RegisterVariableType(list<DeclareVariableNode *> *atr)
{
    this->Name="RegisterVariable";
    this->Attributes=atr;
}



string RegisterVariableType::GetName()
{
    return Name;
}
