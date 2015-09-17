#ifndef REGISTERSTRUCTURENODE_H
#define REGISTERSTRUCTURENODE_H
#include "structurenode.h"
#include "Parser/Expressions/Variables/declarevariablenode.h"
#include "helper.h"

class RegisterStructureNode : public StructureNode
{
public:
    string ID;
    list<DeclareVariableNode*>* Attributes;
    RegisterStructureNode(string Id, list<DeclareVariableNode*>* attr,int row,int column);

    // StructureNode interface
public:
    string ToXML(int i);
};

#endif // REGISTERSTRUCTURENODE_H
