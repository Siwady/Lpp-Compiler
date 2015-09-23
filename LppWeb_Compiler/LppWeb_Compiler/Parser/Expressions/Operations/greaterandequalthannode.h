#ifndef GREATERANDEQUALTHANNODE_H
#define GREATERANDEQUALTHANNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class GreaterAndEqualThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    GreaterAndEqualThanNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // GREATERANDEQUALTHANNODE_H
