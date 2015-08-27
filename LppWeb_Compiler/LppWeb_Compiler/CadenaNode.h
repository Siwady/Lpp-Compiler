#ifndef CADENANODE_H
#define CADENANODE_H
#include <string>
#include "literalnode.h"
using namespace std;

class CadenaNode : public LiteralNode
{
public:
    string Cadena;
    CadenaNode(string cadena);
};

#endif // CADENANODE_H
