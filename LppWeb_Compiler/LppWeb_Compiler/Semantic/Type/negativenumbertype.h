#ifndef NEGATIVENUMBERTYPE_H
#define NEGATIVENUMBERTYPE_H
#include "type.h"
#include "../../Parser/Expressions/expressionnode.h"

class NegativeNumberType : public Type
{
public:
    ExpressionNode * Expression;
    NegativeNumberType(ExpressionNode * exp);

    // Type interface
public:
    string GetName();
};

#endif // NEGATIVENUMBERTYPE_H
