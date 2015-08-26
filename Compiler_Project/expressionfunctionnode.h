#ifndef EXPRESSIONFUNCTIONNODE_H
#define EXPRESSIONFUNCTIONNODE_H
#include <list>
#include "expressionnode.h"

using namespace std;
class ExpressionFunctionNode : public ExpressionNode
{
public:
    string ID;
    list<ExpressionNode*> *Expressions;
    ExpressionFunctionNode();
    ExpressionFunctionNode(string id,list<ExpressionNode*> *expressions);
    void Add(ExpressionNode *expression_node);
};

#endif // EXPRESSIONFUNCTIONNODE_H
