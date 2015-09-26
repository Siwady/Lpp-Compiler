#ifndef STATEMENTSINODE_H
#define STATEMENTSINODE_H
#include "statementnode.h"
#include <list>
#include "../Expressions/expressionnode.h"
using namespace std;

class StatementSiNode : public StatementNode
{
public:
	void Interpret() override;
	~StatementSiNode() override;
	ExpressionNode* Expression;
    list<StatementNode*>* StatementsSi;
    list<StatementNode*>* StatementsSino;
    StatementSiNode(ExpressionNode* expr, list<StatementNode*>* statementSi, list<StatementNode*>* statementsSino,int row,int column);
    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // STATEMENTSINODE_H
