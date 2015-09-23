#ifndef REALNODE_H
#define REALNODE_H
#include"literalnode.h"

class RealNode : public LiteralNode
{
public:
    double Real;
    RealNode(double real,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;



    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // REALNODE_H
