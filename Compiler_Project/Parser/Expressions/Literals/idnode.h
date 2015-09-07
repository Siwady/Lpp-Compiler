#ifndef IDNODE_H
#define IDNODE_H
#include"Parser/Expressions/expressionnode.h"
#include "helper.h"

class IdNode : public ExpressionNode
{
public:
    string ID;
    IdNode(string id);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // IDNODE_H
