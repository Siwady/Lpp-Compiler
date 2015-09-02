#ifndef ARCHIVOTYPENODE_H
#define ARCHIVOTYPENODE_H
#include "typenode.h"
#include <string>
#include "helper.h"
using namespace std;

class ArchivoTypeNode : public TypeNode
{
public:
    string FirstType;
    TypeNode * Type;
    ArchivoTypeNode(string firstType,TypeNode* type);

    // TypeNode interface
public:
    string ToXML(int i);
};

#endif // ARCHIVOTYPENODE_H
