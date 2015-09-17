#ifndef LESSANDEQUALTHANNODE_H
#define LESSANDEQUALTHANNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/Type/booleantype.h"
#include "Semantic/semanticexception.h";

class LessAndEqualThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LessAndEqualThanNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // LESSANDEQUALTHANNODE_H
