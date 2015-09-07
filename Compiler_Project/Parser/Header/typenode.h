#ifndef TYPENODE_H
#define TYPENODE_H
#include <string>
using namespace std;

class TypeNode
{
public:
    TypeNode();
    virtual string ToXML(int i);
};

#endif // TYPENODE_H
