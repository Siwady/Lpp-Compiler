#ifndef GREATERTHANNODE_H
#define GREATERTHANNODE_H
#include "../expressionnode.h"

class GreaterThanNode : public ExpressionNode
{
public:
	~GreaterThanNode() override;
	::Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    GreaterThanNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    string ToXML(int i) override;

    Type* ValidateSemantic() override;
};

#endif // GREATERTHANNODE_H
