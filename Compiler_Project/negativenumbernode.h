#ifndef NEGATIVENUMBERNODE_H
#define NEGATIVENUMBERNODE_H
#include "expressionnode.h"
#include "helper.h"

class NegativeNumberNode : public ExpressionNode
{
public:
    ExpressionNode* Expression;
    NegativeNumberNode(ExpressionNode* expression);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // NEGATIVENUMBERNODE_H
