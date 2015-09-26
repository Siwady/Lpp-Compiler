#ifndef NOTEQUALNODE_H
#define NOTEQUALNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class NotEqualNode : public ExpressionNode
{
public:
	~NotEqualNode() override;
	::Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    NotEqualNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    string ToXML(int i) override;

    Type* ValidateSemantic() override;
};

#endif // NOTEQUALNODE_H
