#ifndef EXPRESSIONGROUPNODE_H
#define EXPRESSIONGROUPNODE_H
#include "expressionnode.h"
#include <list>
using namespace std;
class ExpressionGroupNode : public ExpressionNode
{
public:
    list<ExpressionNode*> *Expressions;
    ExpressionGroupNode();
    ExpressionGroupNode(list<ExpressionNode*> *ls);
};

#endif // EXPRESSIONGROUPNODE_H
