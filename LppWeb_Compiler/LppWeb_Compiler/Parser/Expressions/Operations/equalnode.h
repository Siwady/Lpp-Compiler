#ifndef EQUALNODE_H
#define EQUALNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class EqualNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    EqualNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // EQUALNODE_H
