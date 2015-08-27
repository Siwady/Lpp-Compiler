#ifndef PARAMETERNODE_H
#define PARAMETERNODE_H
#include <string>
#include "typenode.h"

using namespace std;
class ParameterNode
{
public:
    string ID;
    TypeNode* Type;
    bool Var;
    ParameterNode(TypeNode* type,string id,bool var);
};

#endif // PARAMETERNODE_H
