#ifndef CARACTERNODE_H
#define CARACTERNODE_H

#include "literalnode.h"
#include "helper.h"
#include "Semantic/instancetypemanager.h"
class CaracterNode : public LiteralNode
{
public:
    char Caracter;
    CaracterNode(char caracter,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    //Type *ValidateSemantic();

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // CARACTERNODE_H
