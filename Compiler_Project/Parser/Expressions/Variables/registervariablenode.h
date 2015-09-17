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
    RegisterVariableNode(VariableNode* var1,VariableNode* var2, int row,int column);

    string ToXML(int i);

    // ExpressionNode interface
public:
    Type *ValidateSemantic();
};

#endif // REGISTERVARIABLENODE_H
