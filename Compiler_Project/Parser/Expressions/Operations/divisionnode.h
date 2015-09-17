#ifndef DIVISIONNODE_H
#define DIVISIONNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/semanticexception.h"

class DivisionNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    DivisionNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // DIVISIONNODE_H
