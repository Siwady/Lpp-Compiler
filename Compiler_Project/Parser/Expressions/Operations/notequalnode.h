#ifndef NOTEQUALNODE_H
#define NOTEQUALNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/Type/booleantype.h"
#include "Semantic/semanticexception.h";

class NotEqualNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    NotEqualNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // NOTEQUALNODE_H
