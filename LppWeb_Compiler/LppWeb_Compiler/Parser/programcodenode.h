#ifndef PROGRAMCODENODE_H
#define PROGRAMCODENODE_H
#include <string>
using namespace std;

class ProgramCodeNode
{
public:
	virtual ~ProgramCodeNode()
	{
	}

	ProgramCodeNode();
    int Row;
    int Column;
    virtual string ToXML(int i);
    virtual void ValidateSemantic();
	virtual void Interpret();
};

#endif // PROGRAMCODENODE_H
