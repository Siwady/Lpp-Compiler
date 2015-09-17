#ifndef VARIABLENODE_H
#define VARIABLENODE_H
#include "Parser/Expressions/expressionnode.h"

class VariableNode : public ExpressionNode
{
public:
    VariableNode();

    // ExpressionNode interface

public:
    virtual string ToXML(int i);

    // ExpressionNode interface
public:
    virtual Type* ValidateSemantic();
};

#endif // VARIABLENODE_H
