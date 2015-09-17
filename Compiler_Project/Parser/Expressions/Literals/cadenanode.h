#ifndef CADENANODE_H
#define CADENANODE_H
#include <string>
#include "literalnode.h"
#include "helper.h"
#include "Semantic/instancetypemanager.h"
using namespace std;

class CadenaNode : public LiteralNode
{
public:
    string Cadena;
    CadenaNode(string cadena,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);


    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // CADENANODE_H
