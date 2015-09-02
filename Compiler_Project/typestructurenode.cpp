#include "typestructurenode.h"

TypeStructureNode::TypeStructureNode(string id, TypeNode *type)
{
    this->ID=id;
    this->Type=type;
}



string TypeStructureNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<TypeStructure>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+Helper::GetIdentation(i+2)+ID+"h\n";
    re+=Helper::GetIdentation(i+1)+"</ID>\n";
    re+=Type->ToXML(i+1);

    re+=Helper::GetIdentation(i)+"</TypeStructure>\n";
    return re;
}
