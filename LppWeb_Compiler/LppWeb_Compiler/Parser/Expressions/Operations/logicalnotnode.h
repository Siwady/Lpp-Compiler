#ifndef LOGICALNOTNODE_H
#define LOGICALNOTNODE_H
#include "../expressionnode.h"

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
