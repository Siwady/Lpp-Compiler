#ifndef ARRAYTYPENODE_H
#define ARRAYTYPENODE_H
#include "typenode.h"
#include <string>
#include <list>

using namespace std;

class ArrayTypeNode : public TypeNode
{
public:
    TypeNode* Type;
    list<int>* Dimentions;
    ArrayTypeNode(TypeNode* type,list<int>* dim);
};

#endif // ARRAYTYPENODE_H
