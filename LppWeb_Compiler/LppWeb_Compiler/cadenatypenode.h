#ifndef CADENATYPENODE_H
#define CADENATYPENODE_H
#include "typenode.h"
#include <string>

using namespace std;
class CadenaTypeNode : public TypeNode
{
public:
    int Size;
    CadenaTypeNode(int size);
};

#endif // CADENATYPENODE_H
