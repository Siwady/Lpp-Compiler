#ifndef DECLAREVARIABLENODE_H
#define DECLAREVARIABLENODE_H
#include <string>
#include <list>
#include "../../Header/programheadernode.h"
#include "../../Header/typenode.h"
using namespace std;

class DeclareVariableNode:public ProgramHeaderNode
{
public:
    TypeNode* Type;
    list<string>* IDs;
    DeclareVariableNode(TypeNode* type,list<string>* ids,int row,int column);

    string ToXML(int i) override;

    // ProgramHeaderNode interface
public:
    void ValidateSemantic() override;
};

#endif // DECLAREVARIABLENODE_H
