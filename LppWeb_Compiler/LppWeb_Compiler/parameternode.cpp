#include "parameternode.h"

ParameterNode::ParameterNode(TypeNode *type, string id, bool var)
{
    this->ID=id;
    this->Type=type;
    this->Var=var;
}

