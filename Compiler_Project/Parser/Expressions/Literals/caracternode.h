#ifndef CARACTERNODE_H
#define CARACTERNODE_H

#include "literalnode.h"
#include "helper.h"
class CaracterNode : public LiteralNode
{
public:
    char Caracter;
    CaracterNode(char caracter);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // CARACTERNODE_H
