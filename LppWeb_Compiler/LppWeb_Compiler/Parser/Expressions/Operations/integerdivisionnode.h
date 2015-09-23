#ifndef INTEGERDIVISIONNODE_H
#define INTEGERDIVISIONNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class IntegerDivisionNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    IntegerDivisionNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // INTEGERDIVISIONNODE_H
