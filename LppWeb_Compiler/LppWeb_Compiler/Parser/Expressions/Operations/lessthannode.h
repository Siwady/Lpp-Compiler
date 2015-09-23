#ifndef LESSTHANNODE_H
#define LESSTHANNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class LessThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LessThanNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // LESSTHANNODE_H
