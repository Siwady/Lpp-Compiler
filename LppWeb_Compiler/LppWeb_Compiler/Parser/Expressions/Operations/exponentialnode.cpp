#include "exponentialnode.h"
#include "../../../Semantic/semanticexception.h"
#include "../../../helper.h"

ExponentialNode::ExponentialNode(ExpressionNode *left, ExpressionNode *right, int row, int column)
{
    this->LeftNode=left;
    this->RightNode=right;
    this->Row=row;
    this->Column=column;
}



string ExponentialNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ExponentialOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</ExponentialOperation>\n";
    return re;
}


Type *ExponentialNode::ValidateSemantic()
{
    Type* leftNode=LeftNode->ValidateSemantic();
    Type* righNode=RightNode->ValidateSemantic();

    if(leftNode->Name.compare("Entero")==0 && righNode->Name.compare("Entero")==0)
    {
        return leftNode;
    }else if(leftNode->Name.compare("Entero")==0 && righNode->Name.compare("Real")==0)
    {
        return righNode;
    }else if(leftNode->Name.compare("Real")==0 && righNode->Name.compare("Entero")==0)
    {
        return leftNode;
    }else
    {
       throw SemanticException("Tipos de dato incompatibles "+ leftNode->Name+"-"+righNode->Name+",Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }
}
