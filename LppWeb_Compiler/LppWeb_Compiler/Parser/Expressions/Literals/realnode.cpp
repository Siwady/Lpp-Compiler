#include "realnode.h"
#include "../../../helper.h"

RealNode::RealNode(double real, int row, int column)
{
    this->Real=real;
    this->Row=row;
    this->Column=column;
    this->NameType="Real";
}



string RealNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<Real>\n";
    re+=Helper::GetIdentation(i+1)+to_string(Real)+"\n";
    re+=Helper::GetIdentation(i)+"</Real>\n";
    return re;
}

Type *RealNode::ValidateSemantic()
{
    RealType* r=new RealType();
    return r;
}
