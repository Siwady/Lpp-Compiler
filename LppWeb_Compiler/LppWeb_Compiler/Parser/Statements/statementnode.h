#ifndef STATEMENTNODE_H
#define STATEMENTNODE_H
#include <string>
using namespace std;

class StatementNode
{
public:
	virtual ~StatementNode()
	{
	}

	StatementNode();
    int Row;
    int Column;
    virtual string ToXML(int i);
    virtual void ValidateSemantic();
};

#endif // STATEMENTNODE_H
