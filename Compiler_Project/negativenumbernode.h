#ifndef NEGATIVENUMBERNODE_H
#define NEGATIVENUMBERNODE_H
#include "expressionnode.h"

class NegativeNumberNode : public ExpressionNode
{
public:
    ExpressionNode* Expression;
    NegativeNumberNode(ExpressionNode* expression);
};

#endif // NEGATIVENUMBERNODE_H
