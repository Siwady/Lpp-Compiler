#ifndef PARAMETERNODE_H
#define PARAMETERNODE_H
#include <string>

using namespace std;
class ParameterNode
{
public:
    string ID;
    string Type;
    bool Var;
    ParameterNode(string type,string id,bool var);
};

#endif // PARAMETERNODE_H
