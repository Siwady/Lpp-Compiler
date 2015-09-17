#ifndef TYPESTRUCTURENODE_H
#define TYPESTRUCTURENODE_H
#include "structurenode.h"
#include <string>
#include "typenode.h"
#include "helper.h"
using namespace std;

class TypeStructureNode: public StructureNode
{
public:
    string ID;
    TypeNode* Type;
    TypeStructureNode(string id,TypeNode* type,int row,int column);

    // StructureNode interface
public:
    string ToXML(int i);
};

#endif // TYPESTRUCTURENODE_H
