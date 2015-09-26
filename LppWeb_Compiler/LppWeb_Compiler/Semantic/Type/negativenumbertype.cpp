#include "negativenumbertype.h"
#include "../../Interpret/Values/enterovalue.h"

NegativeNumberType::~NegativeNumberType()
{
	delete Expression;
}

Value* NegativeNumberType::DefaultValue()
{
	return new EnteroValue(0);
}

NegativeNumberType::NegativeNumberType(ExpressionNode *exp)
{
    this->Expression=exp;
    this->Name=Expression->NameType;
}



string NegativeNumberType::GetName()
{
    return Name;
}
