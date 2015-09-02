#ifndef VARIABLENODE_H
#define VARIABLENODE_H
#include "expressionnode.h"

class VariableNode : public ExpressionNode
{
public:
    VariableNode();

    // ExpressionNode interface

public:
    virtual string ToXML(int i);
};

#endif // VARIABLENODE_H
