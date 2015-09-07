#ifndef CADENANODE_H
#define CADENANODE_H
#include <string>
#include "literalnode.h"
#include "helper.h"
using namespace std;

class CadenaNode : public LiteralNode
{
public:
    string Cadena;
    CadenaNode(string cadena);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // CADENANODE_H
