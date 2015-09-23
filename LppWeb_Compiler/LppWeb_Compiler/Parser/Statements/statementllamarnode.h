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
    string ID;
    list<ExpressionNode*> * Expressions;
    StatementLlamarNode(string id,list<ExpressionNode*>* ls,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTLLAMARNODE_H
