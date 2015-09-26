#include "typeheadernode.h"
#include "../../helper.h"

TypeHeaderNode::~TypeHeaderNode()
{
	delete TypesStructure;
}

void TypeHeaderNode::Interpret()
{
}

TypeHeaderNode::TypeHeaderNode(list<StructureNode *> *types, int row, int column)
{
    this->TypesStructure=types;
    this->Row=row;
    this->Column=column;
}



string TypeHeaderNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<TypeHeader>\n";

    re+=Helper::GetIdentation(i+1)+"<StructureList>\n";
    for(int j=0;j<TypesStructure->size();j++){
        re+=Helper::GetElementStructureNode(TypesStructure,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StructureList>\n";

    re+=Helper::GetIdentation(i)+"</TypeHeader>\n";
    return re;
}


void TypeHeaderNode::ValidateSemantic()
{
    list<StructureNode*>::const_iterator iterator;
    StructureNode *e;
    for (iterator = TypesStructure->begin(); iterator != TypesStructure->end(); ++iterator) {
        e=*iterator;
        e->ValidateSemantc();
    }
}
