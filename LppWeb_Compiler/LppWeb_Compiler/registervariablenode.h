#ifndef REGISTERVARIABLENODE_H
#define REGISTERVARIABLENODE_H
#include "variablenode.h"

class RegisterVariableNode : public VariableNode
{
public:

    VariableNode* Variable1;
    VariableNode* Variable2;
    RegisterVariableNode();
    RegisterVariableNode(VariableNode* var1,VariableNode* var2);
};

#endif // REGISTERVARIABLENODE_H
