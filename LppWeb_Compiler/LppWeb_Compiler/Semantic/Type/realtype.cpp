#include "realtype.h"
#include "../../Interpret/Values/realvalue.h"

RealType::~RealType()
{
}

Value* RealType::DefaultValue()
{
	return new RealValue(0.0);
}

RealType::RealType()
{
    this->Name="Real";
}



string RealType::GetName()
{
    return Name;
}
