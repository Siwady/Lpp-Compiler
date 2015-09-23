#ifndef SIMPETYPENODE_H
#define SIMPETYPENODE_H
#include "typenode.h"
#include <string>
#include "helper.h"
using namespace std;

class SimpeTypeNode : public TypeNode
{
public:
    SimpeTypeNode(string type,int row,int column);

    // TypeNode interface
public:
    string ToXML(int i);

    // TypeNode interface
public:
    void ValidateSemantic();
};

#endif // SIMPETYPENODE_H
