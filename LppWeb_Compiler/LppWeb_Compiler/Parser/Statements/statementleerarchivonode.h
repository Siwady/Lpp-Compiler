#ifndef STATEMENTLEERARCHIVO_H
#define STATEMENTLEERARCHIVO_H
#include "statementnode.h"
#include <list>
#include "../Expressions/Variables/variablenode.h"

using namespace std;

class StatementLeerArchivoNode : public StatementNode
{
public:
	~StatementLeerArchivoNode() override;
	void Interpret() override;
	list<VariableNode*> *Variables;
    StatementLeerArchivoNode(list<VariableNode*> *var,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // STATEMENTLEERARCHIVO_H
