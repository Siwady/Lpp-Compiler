#ifndef ARRAYVARIABLENODE_H
#define ARRAYVARIABLENODE_H
#include "variablenode.h"
#include "expressionnode.h"
#include <list>
#include <string>
using namespace std;
class ArrayVariableNode : public VariableNode
{
public:
    string ID;
    list<ExpressionNode*> *ExpressionList;
    ArrayVariableNode();
    ArrayVariableNode(list<ExpressionNode*> *ls,string id);
};

#endif // ARRAYVARIABLENODE_H
