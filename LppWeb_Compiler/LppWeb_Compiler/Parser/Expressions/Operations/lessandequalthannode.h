#ifndef LESSANDEQUALTHANNODE_H
#define LESSANDEQUALTHANNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class LessAndEqualThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LessAndEqualThanNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // LESSANDEQUALTHANNODE_H
