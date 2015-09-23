#ifndef ARRAYVARIABLENODE_H
#define ARRAYVARIABLENODE_H
#include "variablenode.h"
#include <list>
#include <string>
using namespace std;

class ArrayVariableNode : public VariableNode
{
public:
    string ID;
    list<ExpressionNode*> *ExpressionList;
    ArrayVariableNode();
    ArrayVariableNode(list<ExpressionNode*> *ls,string id,int row,int column);
    string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // ARRAYVARIABLENODE_H
