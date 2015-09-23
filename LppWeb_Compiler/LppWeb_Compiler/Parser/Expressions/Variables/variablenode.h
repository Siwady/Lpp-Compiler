#ifndef VARIABLENODE_H
#define VARIABLENODE_H
#include "../expressionnode.h"

class VariableNode : public ExpressionNode
{
public:
    VariableNode();

    // ExpressionNode interface

public:
    virtual string ToXML(int i) override;

    // ExpressionNode interface
public:
    virtual Type* ValidateSemantic() override;
};

#endif // VARIABLENODE_H
