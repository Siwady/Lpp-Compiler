#ifndef CARACTERNODE_H
#define CARACTERNODE_H

#include "literalnode.h"

class CaracterNode : public LiteralNode
{
public:
    char Caracter;
    CaracterNode(char caracter);
};

#endif // CARACTERNODE_H
