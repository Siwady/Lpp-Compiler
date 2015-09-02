#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H
#include <string>
using namespace std;

class ExpressionNode
{
public:
    ExpressionNode();
    virtual string ToXML(int i);
};

#endif // EXPRESSIONNODE_H
