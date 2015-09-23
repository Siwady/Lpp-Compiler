#ifndef LITERALNODE_H
#define LITERALNODE_H
#include "../expressionnode.h"

class LiteralNode : public ExpressionNode
{
public:
    LiteralNode();

    // ExpressionNode interface
public:
    virtual string ToXML(int i) override;


    // ExpressionNode interface
public:
    virtual Type *ValidateSemantic() override;
};

#endif // LITERALNODE_H
