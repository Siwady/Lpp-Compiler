#ifndef ARCHIVOTYPENODE_H
#define ARCHIVOTYPENODE_H
#include "typenode.h"
#include <string>
#include "helper.h"
#include "Semantic/symboltable.h"
#include "Parser/Header/arraytypenode.h"
#include "Parser/Header/cadenatypenode.h"
using namespace std;

class ArchivoTypeNode : public TypeNode
{
public:
    string Name;
    TypeNode * Types;
    ArchivoTypeNode(string Name,TypeNode* type,int row,int column);

    // TypeNode interface
public:
    string ToXML(int i);

    // TypeNode interface
public:
    void ValidateSemantic();
};

#endif // ARCHIVOTYPENODE_H
