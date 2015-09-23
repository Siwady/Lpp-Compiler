#ifndef CADENATYPENODE_H
#define CADENATYPENODE_H
#include "typenode.h"
#include <string>

using namespace std;
class CadenaTypeNode : public TypeNode
{
public:
    int Size;
    CadenaTypeNode(int size,int row,int column);

    // TypeNode interface
public:
    string ToXML(int i) override;

    // TypeNode interface
public:
    void ValidateSemantic() override;
};

#endif // CADENATYPENODE_H
