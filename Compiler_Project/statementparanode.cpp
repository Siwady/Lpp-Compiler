#include "statementparanode.h"

StatementParaNode::StatementParaNode(VariableNode *var, ExpressionNode *firstExp, ExpressionNode *secondExp, list<StatementNode *> *ls)
{
    this->Variable=var;
    this->FirstExpression=firstExp;
    this->SecondExpression=secondExp;
    this->Statements=ls;
}

