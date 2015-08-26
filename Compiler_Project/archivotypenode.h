#ifndef ARCHIVOTYPENODE_H
#define ARCHIVOTYPENODE_H
#include "typenode.h"
#include <string>
using namespace std;

class ArchivoTypeNode : public TypeNode
{
public:
    string FirstType;
    TypeNode * Type;
    ArchivoTypeNode(string firstType,TypeNode* type);
};

#endif // ARCHIVOTYPENODE_H
