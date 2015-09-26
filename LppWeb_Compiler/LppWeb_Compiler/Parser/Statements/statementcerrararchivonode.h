#ifndef STATEMENTCERRARARCHIVONODE_H
#define STATEMENTCERRARARCHIVONODE_H
#include "statementnode.h"
#include "../Expressions/Variables/variablenode.h"

class StatementCerrarArchivoNode : public StatementNode
{
public:
	~StatementCerrarArchivoNode() override;
	void Interpret() override;
	VariableNode* Variable;
    StatementCerrarArchivoNode(VariableNode* var,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // STATEMENTCERRARARCHIVONODE_H
