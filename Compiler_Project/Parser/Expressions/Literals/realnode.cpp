#include "realnode.h"

RealNode::RealNode(double real)
{
    this->Real=real;
}



string RealNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<Real>\n";
    re+=Helper::GetIdentation(i+1)+to_string(Real)+"\n";
    re+=Helper::GetIdentation(i)+"</Real>\n";
    return re;
}
