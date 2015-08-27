#ifndef REALNODE_H
#define REALNODE_H
#include"literalnode.h"

class RealNode : public LiteralNode
{
public:
    double Real;
    RealNode(double real);
};

#endif // REALNODE_H
