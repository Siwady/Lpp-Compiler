#include "modnode.h"
#include "../../../helper.h"

ModNode::ModNode(ExpressionNode *left, ExpressionNode *right, int row, int column)
{
    this->LeftNode=left;
    this->RightNode=right;
    this->Row=row;
    this->Column=column;
}



string ModNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ModNodeOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</ModNodeOperation>\n";
    return re;
}


Type *ModNode::ValidateSemantic()
{
    Type* leftNode=LeftNode->ValidateSemantic();
    Type* righNode=RightNode->ValidateSemantic();

    if(leftNode->Name.compare("Entero")==0 && righNode->Name.compare("Entero")==0)
    {
        return leftNode;
    }else
    {
       throw SemanticException("Se esperaba tipo de dato entero "+ leftNode->Name+"-"+righNode->Name+",Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }
}
