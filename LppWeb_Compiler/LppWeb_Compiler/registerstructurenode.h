#ifndef REGISTERSTRUCTURENODE_H
#define REGISTERSTRUCTURENODE_H
#include "structurenode.h"
#include "declarevariablenode.h"

class RegisterStructureNode : public StructureNode
{
public:
    string ID;
    list<DeclareVariableNode*>* Attributes;
    RegisterStructureNode(string Id, list<DeclareVariableNode*>* attr);
};

#endif // REGISTERSTRUCTURENODE_H
