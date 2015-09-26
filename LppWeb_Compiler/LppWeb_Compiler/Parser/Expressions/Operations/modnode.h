#ifndef MODNODE_H
#define MODNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class ModNode : public ExpressionNode
{
public:
	~ModNode() override;
	::Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    ModNode(ExpressionNode* left,ExpressionNode* right, int row,int column);

    string ToXML(int i) override;

    Type* ValidateSemantic() override;
};

#endif // MODNODE_H
