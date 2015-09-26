#ifndef STATEMENTLLAMARNODE_H
#define STATEMENTLLAMARNODE_H
#include "statementnode.h"
#include <string>
#include <list>
#include "../Expressions/expressionnode.h"

using namespace std;

class StatementLlamarNode : public StatementNode
{
public:
	~StatementLlamarNode() override;
	void Interpret() override;
	string ID;
    list<ExpressionNode*> * Expressions;
    StatementLlamarNode(string id,list<ExpressionNode*>* ls,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // STATEMENTLLAMARNODE_H
