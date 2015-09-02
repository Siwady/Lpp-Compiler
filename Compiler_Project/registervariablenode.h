#ifndef REGISTERVARIABLENODE_H
#define REGISTERVARIABLENODE_H
#include "variablenode.h"
#include "helper.h"
class RegisterVariableNode : public VariableNode
{
public:

    VariableNode* Variable1;
    VariableNode* Variable2;
    RegisterVariableNode();
    RegisterVariableNode(VariableNode* var1,VariableNode* var2);

    string ToXML(int i);
};

#endif // REGISTERVARIABLENODE_H
