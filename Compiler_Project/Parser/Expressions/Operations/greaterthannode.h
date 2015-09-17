#ifndef GREATERTHANNODE_H
#define GREATERTHANNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/semanticexception.h"
#include "Semantic/Type/booleantype.h"

class GreaterThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    GreaterThanNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // GREATERTHANNODE_H
