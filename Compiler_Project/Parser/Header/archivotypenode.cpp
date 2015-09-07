#include "archivotypenode.h"

ArchivoTypeNode::ArchivoTypeNode(string firstType, TypeNode *type)
{
    this->FirstType=firstType;
    this->Type=type;
}



string ArchivoTypeNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ArchivoType>\n";
    re+=Helper::GetIdentation(i+1)+"<Type>\n";
    re+=Helper::GetIdentation(i+2)+FirstType+"\n";
    re+=Helper::GetIdentation(i+1)+"</Type>\n";
    re+=Type->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</ArchivoType>\n";

    return re ;
}
