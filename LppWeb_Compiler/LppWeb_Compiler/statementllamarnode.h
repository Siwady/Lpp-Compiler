#ifndef STATEMENTLLAMARNODE_H
#define STATEMENTLLAMARNODE_H
#include "statementnode.h"
#include <string>
#include "expressionnode.h"
#include <list>

using namespace std;

class StatementLlamarNode : public StatementNode
{
public:
    string ID;
    list<ExpressionNode*> * Expressions;
    StatementLlamarNode(string id,list<ExpressionNode*>* ls);
};

#endif // STATEMENTLLAMARNODE_H
