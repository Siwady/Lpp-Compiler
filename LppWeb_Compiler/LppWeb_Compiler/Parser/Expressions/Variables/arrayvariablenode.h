#ifndef ARRAYVARIABLENODE_H
#define ARRAYVARIABLENODE_H
#include "variablenode.h"
#include <list>
#include <string>
using namespace std;

class ArrayVariableNode : public VariableNode
{
public:
	~ArrayVariableNode() override;
	Value* Interpret() override;
    list<ExpressionNode*> *ExpressionList;
    ArrayVariableNode();
    ArrayVariableNode(list<ExpressionNode*> *ls,string id,int row,int column);
    string ToXML(int i) override;

    Type* ValidateSemantic() override;
};

#endif // ARRAYVARIABLENODE_H
