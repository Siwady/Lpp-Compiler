#ifndef SUMNODE_H
#define SUMNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class SumNode : public ExpressionNode
{
public:
	~SumNode() override;
	::Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    SumNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    string ToXML(int i) override;
    Type* ValidateSemantic() override;
};

#endif // SUMNODE_H
