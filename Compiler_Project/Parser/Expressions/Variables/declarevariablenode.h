#ifndef DECLAREVARIABLENODE_H
#define DECLAREVARIABLENODE_H
#include <string>
#include <list>
#include "Parser/Header/typenode.h"
#include "Parser/Header/programheadernode.h"
#include "helper.h"
using namespace std;

class DeclareVariableNode:public ProgramHeaderNode
{
public:
    TypeNode* Type;
    list<string>* IDs;
    DeclareVariableNode(TypeNode* type,list<string>* ids);

    string ToXML(int i);
};

#endif // DECLAREVARIABLENODE_H
