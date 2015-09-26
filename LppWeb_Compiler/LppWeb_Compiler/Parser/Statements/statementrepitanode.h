#ifndef STATEMENTREPITANODE_H
#define STATEMENTREPITANODE_H
#include "statementnode.h"
#include <list>
#include "../Expressions/expressionnode.h"

using namespace std;

class StatementRepitaNode : public StatementNode
{
public:
	~StatementRepitaNode() override;
	void Interpret() override;
	ExpressionNode* Expression;
    list<StatementNode*>* Statements;
    StatementRepitaNode(ExpressionNode* expr,list<StatementNode*>* ls,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // STATEMENTREPITANODE_H
