#ifndef PROGRAMHEADERNODE_H
#define PROGRAMHEADERNODE_H
#include <string>
using namespace std;

class ProgramHeaderNode
{
public:
    ProgramHeaderNode();
    virtual string ToXML(int i);
};

#endif // PROGRAMHEADERNODE_H
