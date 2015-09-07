#ifndef LOGICALNOTNODE_H
#define LOGICALNOTNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
class LogicalNotNode : public ExpressionNode
{
public:
    ExpressionNode *Expression;
    LogicalNotNode(ExpressionNode* expression);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // LOGICALNOTNODE_H
