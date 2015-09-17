#ifndef ARRAYVARIABLENODE_H
#define ARRAYVARIABLENODE_H
#include "variablenode.h"
#include "Parser/Expressions/expressionnode.h"
#include <list>
#include <string>
#include "helper.h"
#include "Semantic/symboltable.h"
#include "Semantic/Type/arreglotype.h"
using namespace std;

class ArrayVariableNode : public VariableNode
{
public:
    string ID;
    list<ExpressionNode*> *ExpressionList;
    ArrayVariableNode();
    ArrayVariableNode(list<ExpressionNode*> *ls,string id,int row,int column);
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // ARRAYVARIABLENODE_H
