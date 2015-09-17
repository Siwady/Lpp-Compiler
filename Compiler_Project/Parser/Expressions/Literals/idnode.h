#ifndef IDNODE_H
#define IDNODE_H
#include"Parser/Expressions/expressionnode.h"
#include "helper.h"

class IdNode : public ExpressionNode
{
public:
    string ID;
    IdNode(string id,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);


    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // IDNODE_H
