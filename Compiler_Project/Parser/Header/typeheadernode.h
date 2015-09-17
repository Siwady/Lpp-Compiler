#ifndef TYPEHEADERNODE_H
#define TYPEHEADERNODE_H
#include "programheadernode.h"
#include "structurenode.h"
#include <list>
#include"helper.h"
using namespace std;

class TypeHeaderNode : public ProgramHeaderNode
{
public:
    list<StructureNode*>* TypesStructure;
    TypeHeaderNode(list<StructureNode*>* types,int row,int column);

    // ProgramHeaderNode interface
public:
    string ToXML(int i);
};

#endif // TYPEHEADERNODE_H
