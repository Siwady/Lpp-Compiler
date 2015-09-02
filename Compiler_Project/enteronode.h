#ifndef ENTERONODE_H
#define ENTERONODE_H
#include "literalnode.h"
#include "helper.h"

class EnteroNode : public LiteralNode
{
public:
    int Entero;
    EnteroNode(int entero);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // ENTERONODE_H
