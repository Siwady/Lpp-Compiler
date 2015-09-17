#ifndef LOGICALNOTNODE_H
#define LOGICALNOTNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/Type/booleantype.h"
#include "Semantic/semanticexception.h"
class LogicalNotNode : public ExpressionNode
{
public:
    ExpressionNode *Expression;
    LogicalNotNode(ExpressionNode* expression, int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type *ValidateSemantic();
};

#endif // LOGICALNOTNODE_H
