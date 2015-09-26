#ifndef STATEMENTESCRIBANODE_H
#define STATEMENTESCRIBANODE_H
#include "statementnode.h"
#include <list>
#include "../Expressions/expressionnode.h"
using namespace std;

class StatementEscribaNode : public StatementNode
{
public:
	~StatementEscribaNode() override;
	void Interpret() override;
	list<ExpressionNode*>*Expressions;
    StatementEscribaNode(list<ExpressionNode*>*expressions,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // STATEMENTESCRIBANODE_H
