#ifndef STATEMENTLLAMARNODE_H
#define STATEMENTLLAMARNODE_H
#include "statementnode.h"
#include <string>
#include "Parser/Expressions/expressionnode.h"
#include <list>
#include "helper.h"
#include "Semantic/symboltable.h"
#include "Semantic/Type/proceduretype.h"
#include "helper.h"

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
