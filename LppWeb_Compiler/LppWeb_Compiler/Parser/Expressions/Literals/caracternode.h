#ifndef CARACTERNODE_H
#define CARACTERNODE_H

#include "literalnode.h"
class CaracterNode : public LiteralNode
{
public:
	Value* Interpret() override;
	~CaracterNode() override;
	char Caracter;
    CaracterNode(char caracter,int row,int column);

public:
    string ToXML(int i) override;
    Type* ValidateSemantic() override;
};

#endif // CARACTERNODE_H
