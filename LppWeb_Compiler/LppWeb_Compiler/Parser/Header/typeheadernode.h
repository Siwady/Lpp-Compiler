#ifndef TYPEHEADERNODE_H
#define TYPEHEADERNODE_H
#include "programheadernode.h"
#include "structurenode.h"
#include <list>
using namespace std;

class TypeHeaderNode : public ProgramHeaderNode
{
public:
	~TypeHeaderNode() override;
	void Interpret() override;
	list<StructureNode*>* TypesStructure;
    TypeHeaderNode(list<StructureNode*>* types,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // TYPEHEADERNODE_H
