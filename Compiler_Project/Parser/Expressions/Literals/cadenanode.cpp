#include "cadenanode.h"

CadenaNode::CadenaNode(string cadena, int row, int column)
{
    this->Cadena=cadena;
    this->Row=row;
    this->Column=column;
    this->NameType="Cadena";
}



string CadenaNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<Cadena>\n";
    re+=Helper::GetIdentation(i)+Cadena+"\n";
    re+=Helper::GetIdentation(i)+"</Cadena>\n";

    return re ;
}


/*Type *CadenaNode::ValidateSemantic()
{
    return InstanceTypeManager::GetCadenaInstance();
}
*/


Type *CadenaNode::ValidateSemantic()
{
    LiteralCadena *c=new LiteralCadena();
    return c;
}
