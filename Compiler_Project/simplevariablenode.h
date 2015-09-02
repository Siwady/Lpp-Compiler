#ifndef SIMPLEVARIABLENODE_H
#define SIMPLEVARIABLENODE_H
#include <string>
#include "variablenode.h"
#include "helper.h"
using namespace std;
class SimpleVariableNode : public VariableNode
{
public:
    string ID;
    SimpleVariableNode(string id);

    string ToXML(int i);
};

#endif // SIMPLEVARIABLENODE_H
