#ifndef LOGICALYNODE_H
#define LOGICALYNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class LogicalYNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LogicalYNode(ExpressionNode* left,ExpressionNode* right, int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // LOGICALYNODE_H
