#ifndef ARRAYVARIABLENODE_H
#define ARRAYVARIABLENODE_H
#include "variablenode.h"
#include "expressionnode.h"
#include <list>
#include <string>
#include "helper.h"
using namespace std;

class ArrayVariableNode : public VariableNode
{
public:
    string ID;
    list<ExpressionNode*> *ExpressionList;
    ArrayVariableNode();
    ArrayVariableNode(list<ExpressionNode*> *ls,string id);

    string ToXML(int i);
};

#endif // ARRAYVARIABLENODE_H
