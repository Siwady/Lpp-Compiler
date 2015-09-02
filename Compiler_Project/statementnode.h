#ifndef STATEMENTNODE_H
#define STATEMENTNODE_H

#include <string>
using namespace std;

class StatementNode
{
public:
    StatementNode();
    virtual string ToXML(int i);
};

#endif // STATEMENTNODE_H
