#ifndef IDNODE_H
#define IDNODE_H
#include "../expressionnode.h"

class IdNode : public ExpressionNode
{
public:
	~IdNode() override;
	Value* Interpret() override;
	string ID;
    IdNode(string id,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;


    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // IDNODE_H
