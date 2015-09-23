#ifndef CADENATYPENODE_H
#define CADENATYPENODE_H
#include "typenode.h"
#include <string>
#include "helper.h"

using namespace std;
class CadenaTypeNode : public TypeNode
{
public:
    int Size;
    CadenaTypeNode(int size,int row,int column);

    // TypeNode interface
public:
    string ToXML(int i);

    // TypeNode interface
public:
    void ValidateSemantic();
};

#endif // CADENATYPENODE_H
