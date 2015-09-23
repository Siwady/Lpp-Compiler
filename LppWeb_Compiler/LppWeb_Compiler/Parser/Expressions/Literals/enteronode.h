#ifndef ENTERONODE_H
#define ENTERONODE_H
#include "literalnode.h"
class EnteroNode : public LiteralNode
{
public:
    int Entero;
    EnteroNode(int entero,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);
    Type* ValidateSemantic();

};

#endif // ENTERONODE_H
