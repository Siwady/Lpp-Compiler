#ifndef PROGRAMCODENODE_H
#define PROGRAMCODENODE_H
#include <string>
#include <iostream>
using namespace std;

class ProgramCodeNode
{
public:
    ProgramCodeNode();
    int Row;
    int Column;
    virtual string ToXML(int i);
    virtual void ValidateSemantic();
};

#endif // PROGRAMCODENODE_H
