#ifndef STATEMENTESCRIBIRARCHIVO_H
#define STATEMENTESCRIBIRARCHIVO_H
#include "statementnode.h"
#include <list>
#include "../Expressions/expressionnode.h"
using namespace std;

class StatementEscribirArchivoNode : public StatementNode
{
public:
	~StatementEscribirArchivoNode() override;
	void Interpret() override;
	list<ExpressionNode*>* Expressions;
    StatementEscribirArchivoNode(list<ExpressionNode*>* ls,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // STATEMENTESCRIBIRARCHIVO_H
