#ifndef ARRAYTYPENODE_H
#define ARRAYTYPENODE_H
#include "typenode.h"

#include <list>


using namespace std;

class ArrayTypeNode : public TypeNode
{
public:
    TypeNode* Type;
    list<int>* Dimentions;
    ArrayTypeNode(TypeNode* type,list<int>* dim,int row,int column);

    // TypeNode interface
public:
    string ToXML(int i);

    // TypeNode interface
public:
    void ValidateSemantic();
};

#endif // ARRAYTYPENODE_H
