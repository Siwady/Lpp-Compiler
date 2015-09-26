#ifndef ARCHIVOTYPENODE_H
#define ARCHIVOTYPENODE_H
#include "typenode.h"
#include <string>
using namespace std;

class ArchivoTypeNode : public TypeNode
{
public:
	void Interpret() override;
	~ArchivoTypeNode() override;
	string Name;
    TypeNode * Types;
    ArchivoTypeNode(string Name,TypeNode* type,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // ARCHIVOTYPENODE_H
