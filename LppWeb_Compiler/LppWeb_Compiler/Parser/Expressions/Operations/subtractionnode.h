#ifndef SUBTRACTIONNODE_H
#define SUBTRACTIONNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class SubtractionNode : public ExpressionNode
{
public:
	~SubtractionNode() override;
	Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    SubtractionNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    string ToXML(int i) override;

    Type* ValidateSemantic() override;
};

#endif // SUBTRACTIONNODE_H
