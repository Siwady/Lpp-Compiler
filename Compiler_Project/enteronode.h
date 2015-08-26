#ifndef ENTERONODE_H
#define ENTERONODE_H
#include "expressionnode.h"

class EnteroNode : public ExpressionNode
{
public:
    int Entero;
    EnteroNode(int entero);
};

#endif // ENTERONODE_H
