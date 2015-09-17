#ifndef SUMNODE_H
#define SUMNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/semanticexception.h";

class SumNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    SumNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // SUMNODE_H
