#ifndef TYPEHEADERNODE_H
#define TYPEHEADERNODE_H
#include "programheadernode.h"
#include "structurenode.h"
#include <list>
using namespace std;

class TypeHeaderNode : public ProgramHeaderNode
{
public:
    list<StructureNode*>* TypesStructure;
    TypeHeaderNode(list<StructureNode*>* types);
};

#endif // TYPEHEADERNODE_H
