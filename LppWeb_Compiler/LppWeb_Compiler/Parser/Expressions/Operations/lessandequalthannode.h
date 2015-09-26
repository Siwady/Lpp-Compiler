#ifndef LESSANDEQUALTHANNODE_H
#define LESSANDEQUALTHANNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class LessAndEqualThanNode : public ExpressionNode
{
public:
	~LessAndEqualThanNode() override;
	::Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LessAndEqualThanNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    string ToXML(int i) override;

    Type* ValidateSemantic() override;
};

#endif // LESSANDEQUALTHANNODE_H
