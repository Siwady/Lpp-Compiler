#ifndef OPERATIONNODE_H
#define OPERATIONNODE_H
#include "Parser/Expressions/expressionnode.h"

class OperationNode : public ExpressionNode
{
public:
    OperationNode();

    virtual string ToXML(int i);

    Type *ValidateSemantic();
};

#endif // OPERATIONNODE_H
