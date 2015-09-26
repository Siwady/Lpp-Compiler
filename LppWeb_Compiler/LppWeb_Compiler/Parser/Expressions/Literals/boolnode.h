#ifndef BOOLNODE_H
#define BOOLNODE_H
#include <string>
#include "../expressionnode.h"

using namespace std;

class BoolNode : public ExpressionNode
{
public:
	Value* Interpret() override;
	~BoolNode() override;
	string Booolean;
    BoolNode(string boolean,int row,int column);

    string ToXML(int i) override;

    Type *ValidateSemantic() override;
};

#endif // BOOLNODE_H
