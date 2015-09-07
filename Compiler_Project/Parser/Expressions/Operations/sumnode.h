#ifndef SUMNODE_H
#define SUMNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"

class SumNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    SumNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // SUMNODE_H
