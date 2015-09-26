#include "statementabrirarchivonode.h"
#include "../../Semantic/semanticexception.h"
#include "../../helper.h"

StatementAbrirArchivoNode::~StatementAbrirArchivoNode()
{
	delete Expression;
	delete Variable;
	delete Operators;
}

void StatementAbrirArchivoNode::Interpret()
{
}

StatementAbrirArchivoNode::StatementAbrirArchivoNode(ExpressionNode *expr, VariableNode *var, list<string> *op, int row, int column)
{
    this->Expression=expr;
    this->Variable=var;
    this->Operators=op;
    this->Row=row;
    this->Column=column;
}



string StatementAbrirArchivoNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementAbrirArchivo>\n";
    re+=Expression->ToXML(i+1);

    re+=Variable->ToXML(i+1);

    re+=Helper::GetIdentation(i+1)+"<Operators>\n";
    for(int j=0;j<Operators->size();j++){
        re+=Helper::GetIdentation(i+2)+Helper::GetElementString(Operators,j);
    }
    re+=Helper::GetIdentation(i+1)+"</Operators>\n";

    re+=Helper::GetIdentation(i)+"</StatementAbrirArchivo>\n";
    return re;
}

void StatementAbrirArchivoNode::ValidateSemantic()
{
    if(Expression->ValidateSemantic()->Name!="Cadena")
    {
        throw SemanticException("Se esperaba una Cadena ,Fila:"+to_string(Expression->Row)+",Columna:"+to_string(Expression->Column));
    }

    Variable->ValidateSemantic();
    if(Operators->size()>2)
    {
        throw SemanticException("Solo puede haber un Lectura y una Escritura:"+to_string(Expression->Row)+",Columna:"+to_string(Expression->Column));
    }
    list<string>::const_iterator iterator;
    string temp;
    for (iterator = Operators->begin(); iterator != Operators->end(); ++iterator) {

        if(temp.compare("")!=0)
        {
            if(temp.compare(*iterator)==0){
                throw SemanticException("Se esperaba tipo de dato entero,Fila:"+to_string(Row)+",Columna:"+to_string(Column));

            }
        }
        temp=*iterator;
    }
}
