#ifndef LOGICALYNODE_H
#define LOGICALYNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/Type/booleantype.h"
//#include "Semantic/semanticexception.h";

class LogicalYNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LogicalYNode(ExpressionNode* left,ExpressionNode* right, int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // LOGICALYNODE_H
