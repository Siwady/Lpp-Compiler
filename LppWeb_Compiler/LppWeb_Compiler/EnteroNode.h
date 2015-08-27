#ifndef ENTERONODE_H
#define ENTERONODE_H
#include "literalnode.h"

class EnteroNode : public LiteralNode
{
public:
    int Entero;
    EnteroNode(int entero);
};

#endif // ENTERONODE_H
