#ifndef REALNODE_H
#define REALNODE_H
#include"literalnode.h"
#include "helper.h"

class RealNode : public LiteralNode
{
public:
    double Real;
    RealNode(double real);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // REALNODE_H
