#ifndef PROGRAMCODENODE_H
#define PROGRAMCODENODE_H
#include <string>
using namespace std;

class ProgramCodeNode
{
public:
    ProgramCodeNode();
    virtual string ToXML(int i);
};

#endif // PROGRAMCODENODE_H
