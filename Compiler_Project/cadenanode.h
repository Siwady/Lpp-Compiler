#ifndef CADENANODE_H
#define CADENANODE_H
#include <string>
#include "expressionnode.h"
using namespace std;

class CadenaNode : public ExpressionNode
{
public:
    string Cadena;
    CadenaNode(string cadena);
};

#endif // CADENANODE_H
