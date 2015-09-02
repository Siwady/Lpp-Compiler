#ifndef REGISTERSTRUCTURENODE_H
#define REGISTERSTRUCTURENODE_H
#include "structurenode.h"
#include "declarevariablenode.h"
#include "helper.h"

class RegisterStructureNode : public StructureNode
{
public:
    string ID;
    list<DeclareVariableNode*>* Attributes;
    RegisterStructureNode(string Id, list<DeclareVariableNode*>* attr);

    // StructureNode interface
public:
    string ToXML(int i);
};

#endif // REGISTERSTRUCTURENODE_H
