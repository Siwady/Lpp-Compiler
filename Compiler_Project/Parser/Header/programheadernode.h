#ifndef PROGRAMHEADERNODE_H
#define PROGRAMHEADERNODE_H
#include <string>
using namespace std;

class ProgramHeaderNode
{
public:
    ProgramHeaderNode();
    int Row;
    int Column;
    virtual string ToXML(int i);
    virtual void ValidateSemantic();
};

#endif // PROGRAMHEADERNODE_H
