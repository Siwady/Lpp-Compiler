#ifndef TYPENODE_H
#define TYPENODE_H
#include <string>
using namespace std;

class TypeNode
{
public:
	virtual ~TypeNode()
	{
	}

	TypeNode();
    string OfType;
    int Row;
    int Column;
    virtual string ToXML(int i);
    virtual void ValidateSemantic();
};

#endif // TYPENODE_H
