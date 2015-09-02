#include "typeheadernode.h"

TypeHeaderNode::TypeHeaderNode(list<StructureNode *> *types)
{
    this->TypesStructure=types;
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
