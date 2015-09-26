#ifndef STATEMENTCASONODE_H
#define STATEMENTCASONODE_H
#include "statementnode.h"
#include "casenode.h"
#include "../Expressions/Variables/variablenode.h"


class StatementCasoNode : public StatementNode
{
public:
	~StatementCasoNode() override;
	void Interpret() override;
	VariableNode* Variable;
    list<CaseNode*>* Cases;
    list<StatementNode*>* SinoCase;
    StatementCasoNode(VariableNode* var,list<CaseNode*>* cases,list<StatementNode*>* sinocase,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // STATEMENTCASONODE_H
