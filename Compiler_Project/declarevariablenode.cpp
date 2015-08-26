#include "declarevariablenode.h"

DeclareVariableNode::DeclareVariableNode(TypeNode *type, list<string> *ids)
{
    this->IDs=ids;
    this->Type=type;
}

