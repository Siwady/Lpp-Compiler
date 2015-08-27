#ifndef BOOLNODE_H
#define BOOLNODE_H
#include <string>
#include "expressionnode.h"
using namespace std;

class BoolNode : public ExpressionNode
{
public:
    string Booolean;
    BoolNode(string boolean);
};

#endif // BOOLNODE_H
