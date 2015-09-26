#ifndef GREATERANDEQUALTHANNODE_H
#define GREATERANDEQUALTHANNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class GreaterAndEqualThanNode : public ExpressionNode
{
public:
	~GreaterAndEqualThanNode() override;
	Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    GreaterAndEqualThanNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    string ToXML(int i) override;

    Type* ValidateSemantic() override;
};

#endif // GREATERANDEQUALTHANNODE_H
