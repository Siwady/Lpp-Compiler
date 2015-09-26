#ifndef ENTERONODE_H
#define ENTERONODE_H
#include "literalnode.h"
class EnteroNode : public LiteralNode
{
public:
	Value* Interpret() override;
	~EnteroNode() override;
	int Entero;
    EnteroNode(int entero,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;
    Type* ValidateSemantic() override;

};

#endif // ENTERONODE_H
