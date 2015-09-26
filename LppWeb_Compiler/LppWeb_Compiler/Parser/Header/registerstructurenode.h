#ifndef REGISTERSTRUCTURENODE_H
#define REGISTERSTRUCTURENODE_H
#include "structurenode.h"
#include <list>
#include "../Expressions/Variables/declarevariablenode.h"

class RegisterStructureNode : public StructureNode
{
public:
	~RegisterStructureNode() override;
	void Interpret() override;
	string ID;
    list<DeclareVariableNode*>* Attributes;
    RegisterStructureNode(string Id, list<DeclareVariableNode*>* attr,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantc() override;
};

#endif // REGISTERSTRUCTURENODE_H
