#ifndef PROGRAMHEADERNODE_H
#define PROGRAMHEADERNODE_H
#include <string>
using namespace std;

class ProgramHeaderNode
{
public:
	virtual ~ProgramHeaderNode()
	{
	}

	ProgramHeaderNode();
    int Row;
    int Column;
    virtual string ToXML(int i);
    virtual void ValidateSemantic();
	virtual void Interpret();
};

#endif // PROGRAMHEADERNODE_H
