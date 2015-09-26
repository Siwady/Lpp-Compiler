#ifndef LOGICALONODE_H
#define LOGICALONODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class LogicalONode : public ExpressionNode
{
public:
	~LogicalONode() override;
	Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LogicalONode(ExpressionNode* left,ExpressionNode* right, int row,int column);

    string ToXML(int i) override;

    Type* ValidateSemantic() override;
};

#endif // LOGICALONODE_H
