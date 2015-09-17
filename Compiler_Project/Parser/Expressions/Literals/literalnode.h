#ifndef LITERALNODE_H
#define LITERALNODE_H
#include "Parser/Expressions/expressionnode.h"

class LiteralNode : public ExpressionNode
{
public:
    LiteralNode();

    // ExpressionNode interface
public:
    virtual string ToXML(int i);


    // ExpressionNode interface
public:
    virtual Type *ValidateSemantic();
};

#endif // LITERALNODE_H
