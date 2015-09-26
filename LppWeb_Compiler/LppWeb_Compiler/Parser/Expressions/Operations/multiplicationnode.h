#ifndef MULTIPLICATIONNODE_H
#define MULTIPLICATIONNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class MultiplicationNode : public ExpressionNode
{
public:
	~MultiplicationNode() override;
	Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    MultiplicationNode(ExpressionNode* left,ExpressionNode* right, int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // MULTIPLICATIONNODE_H
