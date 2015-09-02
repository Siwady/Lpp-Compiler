#ifndef BOOLNODE_H
#define BOOLNODE_H
#include <string>
#include "expressionnode.h"
#include "helper.h"
using namespace std;

class BoolNode : public ExpressionNode
{
public:
    string Booolean;
    BoolNode(string boolean);

    string ToXML(int i);
};

#endif // BOOLNODE_H
