#ifndef LESSTHANNODE_H
#define LESSTHANNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/Type/booleantype.h"
#include "Semantic/semanticexception.h";

class LessThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LessThanNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // LESSTHANNODE_H
