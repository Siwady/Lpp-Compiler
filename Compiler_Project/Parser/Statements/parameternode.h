#ifndef PARAMETERNODE_H
#define PARAMETERNODE_H
#include <string>
#include "Parser/Header/typenode.h"
#include "helper.h"

using namespace std;
class ParameterNode
{
public:
    string ID;
    TypeNode* Type;
    bool Var;
    ParameterNode(TypeNode* type,string id,bool var);
    string ToXML(int i);
};

#endif // PARAMETERNODE_H
