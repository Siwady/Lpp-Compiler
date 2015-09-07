#ifndef ARRAYTYPENODE_H
#define ARRAYTYPENODE_H
#include "typenode.h"

#include "helper.h"


using namespace std;

class ArrayTypeNode : public TypeNode
{
public:
    TypeNode* Type;
    list<int>* Dimentions;
    ArrayTypeNode(TypeNode* type,list<int>* dim);

    // TypeNode interface
public:
    string ToXML(int i);
};

#endif // ARRAYTYPENODE_H
