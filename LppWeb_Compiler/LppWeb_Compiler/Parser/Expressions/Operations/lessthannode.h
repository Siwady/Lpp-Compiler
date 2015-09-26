#ifndef LESSTHANNODE_H
#define LESSTHANNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class LessThanNode : public ExpressionNode
{
public:
	~LessThanNode() override;
	::Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LessThanNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    string ToXML(int i) override;

    Type* ValidateSemantic() override;
};

#endif // LESSTHANNODE_H
