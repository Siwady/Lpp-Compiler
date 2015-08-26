#ifndef SIMPLEVARIABLENODE_H
#define SIMPLEVARIABLENODE_H
#include <string>
#include "variablenode.h"
using namespace std;
class SimpleVariableNode : public VariableNode
{
public:
    string ID;
    SimpleVariableNode(string id);
};

#endif // SIMPLEVARIABLENODE_H
