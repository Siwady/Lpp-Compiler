#ifndef SUBTRACTIONNODE_H
#define SUBTRACTIONNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"

class SubtractionNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    SubtractionNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // SUBTRACTIONNODE_H
