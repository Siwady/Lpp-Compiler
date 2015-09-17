#include "logicalnotnode.h"

LogicalNotNode::LogicalNotNode(ExpressionNode *expression, int row, int column)
{
    this->Expression=expression;
    this->Row=row;
    this->Column=column;
}



string LogicalNotNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<LogicalNotOperation>\n";
    re+=Expression->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</LogicalNotOperation>\n";
    return re;
}


Type *LogicalNotNode::ValidateSemantic()
{
    BooleanType *b=new BooleanType();
    if(Expression->ValidateSemantic()->Name.compare("Booleano")!=0)
    {
        throw SemanticException("Se esperaba tipo de dato Booleano ,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }
    return b;
}
