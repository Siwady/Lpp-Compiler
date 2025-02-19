#ifndef DECLAREHEADERNODE_H
#define DECLAREHEADERNODE_H
#include "programheadernode.h"
#include <list>
#include "Parser/Expressions/Variables/declarevariablenode.h"
#include "helper.h"
using namespace std;
class DeclareHeaderNode : public ProgramHeaderNode
{
public:
    list<DeclareVariableNode*>* DeclareVariables;
    DeclareHeaderNode(list<DeclareVariableNode*>* var,int row,int column);
    string ToXML(int i);

    // ProgramHeaderNode interface
public:
    void ValidateSemantic();
};

#endif // DECLAREHEADERNODE_H
