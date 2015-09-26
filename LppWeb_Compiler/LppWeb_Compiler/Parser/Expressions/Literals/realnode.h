#ifndef REALNODE_H
#define REALNODE_H
#include"literalnode.h"

class RealNode : public LiteralNode
{
public:
	~RealNode() override;
	Value* Interpret() override;
	double Real;
    RealNode(double real,int row,int column);

    string ToXML(int i) override;
    Type* ValidateSemantic() override;
};

#endif // REALNODE_H
