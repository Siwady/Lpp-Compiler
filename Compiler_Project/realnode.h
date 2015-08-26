#ifndef REALNODE_H
#define REALNODE_H
#include"expressionnode.h"

class RealNode : public ExpressionNode
{
public:
    double Real;
    RealNode(double real);
};

#endif // REALNODE_H
