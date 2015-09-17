#include "negativenumbertype.h"

NegativeNumberType::NegativeNumberType(ExpressionNode *exp)
{
    this->Expression=exp;
    this->Name=Expression->NameType;
}



string NegativeNumberType::GetName()
{
    return Name;
}
