#ifndef DECLAREHEADERNODE_H
#define DECLAREHEADERNODE_H
#include "programheadernode.h"
#include <list>
#include "../Expressions/Variables/declarevariablenode.h"
using namespace std;
class DeclareHeaderNode : public ProgramHeaderNode
{
public:
	~DeclareHeaderNode() override;
	void Interpret() override;
	list<DeclareVariableNode*>* DeclareVariables;
    DeclareHeaderNode(list<DeclareVariableNode*>* var,int row,int column);
    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // DECLAREHEADERNODE_H
