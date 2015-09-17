#ifndef INTEGERDIVISIONNODE_H
#define INTEGERDIVISIONNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "Semantic/Type/enterotype.h"
#include "helper.h"
#include "Semantic/semanticexception.h";

class IntegerDivisionNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    IntegerDivisionNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // INTEGERDIVISIONNODE_H
