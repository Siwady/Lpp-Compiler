#ifndef STRUCTURENODE_H
#define STRUCTURENODE_H
#include <string>
using namespace std;

class StructureNode
{
public:
    StructureNode();
    virtual string ToXML(int i);
};

#endif // STRUCTURENODE_H
