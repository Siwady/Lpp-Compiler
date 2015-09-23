#ifndef SUBTRACTIONNODE_H
#define SUBTRACTIONNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class SubtractionNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    SubtractionNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // SUBTRACTIONNODE_H
