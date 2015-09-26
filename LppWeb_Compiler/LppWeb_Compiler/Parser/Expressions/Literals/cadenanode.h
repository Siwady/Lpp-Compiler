#ifndef CADENANODE_H
#define CADENANODE_H
#include <string>
#include "literalnode.h"
using namespace std;

class CadenaNode : public LiteralNode
{
public:
	Value* Interpret() override;
	~CadenaNode() override;
	string Cadena;
    CadenaNode(string cadena,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;
    Type* ValidateSemantic() override;
};

#endif // CADENANODE_H
