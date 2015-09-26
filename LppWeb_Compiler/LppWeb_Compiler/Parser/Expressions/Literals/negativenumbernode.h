#ifndef NEGATIVENUMBERNODE_H
#define NEGATIVENUMBERNODE_H
#include "../expressionnode.h"

class NegativeNumberNode : public ExpressionNode
{
public:
	~NegativeNumberNode() override;
	Value* Interpret() override;
	ExpressionNode* Expression;
    NegativeNumberNode(ExpressionNode* expression,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;


    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // NEGATIVENUMBERNODE_H
