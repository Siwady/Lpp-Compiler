#ifndef ARRAYTYPENODE_H
#define ARRAYTYPENODE_H
#include "typenode.h"

#include <list>


using namespace std;

class ArrayTypeNode : public TypeNode
{
public:
	~ArrayTypeNode() override;
	void Interpret() override;
	TypeNode* Type;
    list<int>* Dimentions;
    ArrayTypeNode(TypeNode* type,list<int>* dim,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // ARRAYTYPENODE_H
