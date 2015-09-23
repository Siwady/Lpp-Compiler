#ifndef PROCEDURENODE_H
#define PROCEDURENODE_H
#include "statementnode.h"
#include "parameternode.h"
#include "../Header/programheadernode.h"
#include <list>
#include "../Expressions/Variables/declarevariablenode.h"

class ProcedureNode : public ProgramHeaderNode
{
public:
	~ProcedureNode() override;
	void ValidateSemantic() override;
	string ID;
    list<ParameterNode*>* Params;
    list<DeclareVariableNode*>* Variables;
    list<StatementNode*>* Statements;
    ProcedureNode(string id, list<ParameterNode*>* param, list<DeclareVariableNode*>* vars, list<StatementNode*>* statements,int row,int column);
    ProcedureNode();

    string ToXML(int i) override;
};

#endif // PROCEDURENODE_H
