#ifndef TYPESTRUCTURENODE_H
#define TYPESTRUCTURENODE_H
#include "structurenode.h"
#include <string>
#include "typenode.h"
using namespace std;


class TypeStructureNode: public StructureNode
{
public:
    string ID;
    TypeNode* Type;
    TypeStructureNode(string id,TypeNode* type,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantc() override;
};

#endif // TYPESTRUCTURENODE_H
