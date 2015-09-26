#ifndef STATEMENTMIENTRASNODE_H
#define STATEMENTMIENTRASNODE_H
#include "statementnode.h"
#include <list>
#include "../Expressions/expressionnode.h"

using namespace std;

class StatementMientrasNode : public StatementNode
{
public:
	~StatementMientrasNode() override;
	void Interpret() override;
	ExpressionNode* Expression;
    list<StatementNode*>*Statements;
    StatementMientrasNode(ExpressionNode* expr,list<StatementNode*>* ls,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // STATEMENTMIENTRASNODE_H
