#ifndef IDNODE_H
#define IDNODE_H
#include"expressionnode.h"
#include <string>
using namespace std;

class IdNode : public ExpressionNode
{
public:
    string ID;
    IdNode(string id);
};

#endif // IDNODE_H
