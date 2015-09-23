#ifndef ARCHIVOTYPENODE_H
#define ARCHIVOTYPENODE_H
#include "typenode.h"
#include <string>
using namespace std;

class ArchivoTypeNode : public TypeNode
{
public:
    string Name;
    TypeNode * Types;
    ArchivoTypeNode(string Name,TypeNode* type,int row,int column);

    // TypeNode interface
public:
    string ToXML(int i) override;

    // TypeNode interface
public:
    void ValidateSemantic() override;
};

#endif // ARCHIVOTYPENODE_H
