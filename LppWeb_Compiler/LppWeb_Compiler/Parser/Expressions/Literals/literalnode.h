#ifndef LITERALNODE_H
#define LITERALNODE_H
#include "../expressionnode.h"

class LiteralNode : public ExpressionNode
{
public:
	~LiteralNode() override;
	virtual Value* Interpret() override;
	LiteralNode();

    virtual string ToXML(int i) override;

    virtual Type *ValidateSemantic() override;
};

#endif // LITERALNODE_H
