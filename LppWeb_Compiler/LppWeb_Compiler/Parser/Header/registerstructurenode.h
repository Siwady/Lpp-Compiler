#ifndef REGISTERSTRUCTURENODE_H
#define REGISTERSTRUCTURENODE_H
#include "structurenode.h"
#include <list>
#include "../Expressions/Variables/declarevariablenode.h"

class RegisterStructureNode : public StructureNode
{
public:
    string ID;
    list<DeclareVariableNode*>* Attributes;
    RegisterStructureNode(string Id, list<DeclareVariableNode*>* attr,int row,int column);

    // StructureNode interface
public:
    string ToXML(int i) override;

    // StructureNode interface
public:
    void ValidateSemantc() override;
};

#endif // REGISTERSTRUCTURENODE_H
