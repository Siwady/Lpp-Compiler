#ifndef LOGICALONODE_H
#define LOGICALONODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class LogicalONode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LogicalONode(ExpressionNode* left,ExpressionNode* right, int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // LOGICALONODE_H
