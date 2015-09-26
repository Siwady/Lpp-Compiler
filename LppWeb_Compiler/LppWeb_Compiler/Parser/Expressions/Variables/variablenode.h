#ifndef VARIABLENODE_H
#define VARIABLENODE_H
#include "../expressionnode.h"

class VariableNode : public ExpressionNode
{
public:
	~VariableNode() override;
	virtual Value* Interpret() override;
	VariableNode();
	string ID;
    virtual string ToXML(int i) override;

    virtual Type* ValidateSemantic() override;
};

#endif // VARIABLENODE_H
