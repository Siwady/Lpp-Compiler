#ifndef LESSANDEQUALTHANNODE_H
#define LESSANDEQUALTHANNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"

class LessAndEqualThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LessAndEqualThanNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // LESSANDEQUALTHANNODE_H
