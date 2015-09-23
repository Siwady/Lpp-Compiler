#ifndef NOTEQUALNODE_H
#define NOTEQUALNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class NotEqualNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    NotEqualNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // NOTEQUALNODE_H
