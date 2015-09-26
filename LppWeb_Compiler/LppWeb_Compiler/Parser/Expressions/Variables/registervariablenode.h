#ifndef REGISTERVARIABLENODE_H
#define REGISTERVARIABLENODE_H
#include "variablenode.h"
class RegisterVariableNode : public VariableNode
{
public:
	~RegisterVariableNode() override;
	Value* Interpret() override;
	VariableNode* Variable1;
    VariableNode* Variable2;
    RegisterVariableNode();
    RegisterVariableNode(VariableNode* var1,VariableNode* var2, int row,int column);

    string ToXML(int i) override;

    Type *ValidateSemantic() override;
};

#endif // REGISTERVARIABLENODE_H
