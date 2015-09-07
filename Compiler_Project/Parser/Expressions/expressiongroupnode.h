#ifndef EXPRESSIONGROUPNODE_H
#define EXPRESSIONGROUPNODE_H
#include "expressionnode.h"
#include <list>
#include "helper.h"
using namespace std;
class ExpressionGroupNode : public ExpressionNode
{
public:
    list<ExpressionNode*> *Expressions;
    ExpressionGroupNode();
    ExpressionGroupNode(list<ExpressionNode*> *ls);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // EXPRESSIONGROUPNODE_H
