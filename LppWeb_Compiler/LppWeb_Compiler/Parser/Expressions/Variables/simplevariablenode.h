#ifndef SIMPLEVARIABLENODE_H
#define SIMPLEVARIABLENODE_H
#include <string>
#include "variablenode.h"
using namespace std;
class SimpleVariableNode : public VariableNode
{
public:
    string ID;
    SimpleVariableNode(string id,int row,int column);
    string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type *ValidateSemantic() override;
};

#endif // SIMPLEVARIABLENODE_H
