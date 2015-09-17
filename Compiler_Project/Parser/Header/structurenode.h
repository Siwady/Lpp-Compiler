#ifndef STRUCTURENODE_H
#define STRUCTURENODE_H
#include <string>
using namespace std;

class StructureNode
{
public:
    StructureNode();
    int Row;
    int Column;
    virtual string ToXML(int i);
};

#endif // STRUCTURENODE_H
