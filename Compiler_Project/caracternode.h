#ifndef CARACTERNODE_H
#define CARACTERNODE_H

#include "expressionnode.h"

class CaracterNode : public ExpressionNode
{
public:
    char Caracter;
    CaracterNode(char caracter);
};

#endif // CARACTERNODE_H
