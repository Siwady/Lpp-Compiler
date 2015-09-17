#ifndef SIMPLEVARIABLENODE_H
#define SIMPLEVARIABLENODE_H
#include <string>
#include "variablenode.h"
#include "helper.h"
#include "Semantic/symboltable.h"
#include "Semantic/Type/simplevariabletype.h"
using namespace std;
class SimpleVariableNode : public VariableNode
{
public:
    string ID;
    SimpleVariableNode(string id,int row,int column);
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type *ValidateSemantic();
};

#endif // SIMPLEVARIABLENODE_H
