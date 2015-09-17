#ifndef EQUALNODE_H
#define EQUALNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/Type/booleantype.h"
#include "Semantic/semanticexception.h";

class EqualNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    EqualNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // EQUALNODE_H
