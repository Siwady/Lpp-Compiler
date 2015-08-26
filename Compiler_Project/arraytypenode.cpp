#include "arraytypenode.h"

ArrayTypeNode::ArrayTypeNode(TypeNode *type, list<int> *dim)
{
    this->Type=type;
    this->Dimentions=dim;
}

