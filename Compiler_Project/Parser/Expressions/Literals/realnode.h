#ifndef REALNODE_H
#define REALNODE_H
#include"literalnode.h"
#include "helper.h"
#include "Semantic/instancetypemanager.h"

class RealNode : public LiteralNode
{
public:
    double Real;
    RealNode(double real,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);



    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // REALNODE_H
