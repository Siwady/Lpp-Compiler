#ifndef MODNODE_H
#define MODNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/semanticexception.h";

class ModNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    ModNode(ExpressionNode* left,ExpressionNode* right, int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // MODNODE_H
