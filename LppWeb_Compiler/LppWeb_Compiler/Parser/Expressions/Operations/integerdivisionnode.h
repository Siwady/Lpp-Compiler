#ifndef INTEGERDIVISIONNODE_H
#define INTEGERDIVISIONNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class IntegerDivisionNode : public ExpressionNode
{
public:
	~IntegerDivisionNode() override;
	::Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    IntegerDivisionNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    string ToXML(int i) override;

    Type* ValidateSemantic() override;
};

#endif // INTEGERDIVISIONNODE_H
