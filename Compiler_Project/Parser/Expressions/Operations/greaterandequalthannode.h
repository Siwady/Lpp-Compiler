#ifndef GREATERANDEQUALTHANNODE_H
#define GREATERANDEQUALTHANNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/Type/booleantype.h"
#include "Semantic/semanticexception.h";

class GreaterAndEqualThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    GreaterAndEqualThanNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // GREATERANDEQUALTHANNODE_H
