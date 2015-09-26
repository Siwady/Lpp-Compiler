#ifndef NEGATIVENUMBERTYPE_H
#define NEGATIVENUMBERTYPE_H
#include "type.h"
#include "../../Parser/Expressions/expressionnode.h"

class NegativeNumberType : public Type
{
public:
	~NegativeNumberType() override;
	Value* DefaultValue() override;
	ExpressionNode * Expression;
    NegativeNumberType(ExpressionNode * exp);

    string GetName() override;
};

#endif // NEGATIVENUMBERTYPE_H
