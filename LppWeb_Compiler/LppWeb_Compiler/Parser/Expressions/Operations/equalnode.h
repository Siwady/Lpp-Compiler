#ifndef EQUALNODE_H
#define EQUALNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class EqualNode : public ExpressionNode
{
public:
	~EqualNode() override;
	::Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    EqualNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    string ToXML(int i) override;

    Type* ValidateSemantic() override;
};

#endif // EQUALNODE_H
