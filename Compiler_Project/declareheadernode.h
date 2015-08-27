#ifndef DECLAREHEADERNODE_H
#define DECLAREHEADERNODE_H
#include "programheadernode.h"
#include <list>
#include "declarevariablenode.h"
using namespace std;
class DeclareHeaderNode : public ProgramHeaderNode
{
public:
    list<DeclareVariableNode*>* DeclareVariables;
    DeclareHeaderNode(list<DeclareVariableNode*>* var);
};

#endif // DECLAREHEADERNODE_H
