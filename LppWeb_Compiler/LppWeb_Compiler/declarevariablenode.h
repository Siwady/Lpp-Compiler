#ifndef DECLAREVARIABLENODE_H
#define DECLAREVARIABLENODE_H
#include <string>
#include <list>
#include "typenode.h"
#include "programheadernode.h"

using namespace std;

class DeclareVariableNode:public ProgramHeaderNode
{
public:
    TypeNode* Type;
    list<string>* IDs;
    DeclareVariableNode(TypeNode* type,list<string>* ids);
};

#endif // DECLAREVARIABLENODE_H
