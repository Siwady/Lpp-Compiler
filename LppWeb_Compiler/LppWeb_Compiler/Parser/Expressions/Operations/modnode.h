#ifndef MODNODE_H
#define MODNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class ModNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    ModNode(ExpressionNode* left,ExpressionNode* right, int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // MODNODE_H
