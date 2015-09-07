#ifndef MULTIPLICATIONNODE_H
#define MULTIPLICATIONNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"

class MultiplicationNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    MultiplicationNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // MULTIPLICATIONNODE_H
