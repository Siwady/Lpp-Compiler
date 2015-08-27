#include "registerstructurenode.h"

RegisterStructureNode::RegisterStructureNode(string Id, list<DeclareVariableNode *> *attr)
{
    this->ID=Id;
    this->Attributes=attr;
}

