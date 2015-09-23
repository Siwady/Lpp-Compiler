#include "statementmientrasnode.h"
#include "../../Semantic/semanticexception.h"
#include "../../helper.h"

StatementMientrasNode::StatementMientrasNode(ExpressionNode *expr, list<StatementNode *> *ls, int row, int column)
{
    this->Expression=expr;
    this->Statements=ls;
    this->Row=row;
    this->Column=column;
}



string StatementMientrasNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementMientras>\n";

    re+=Expression->ToXML(i+1);

    re+=Helper::GetIdentation(i+1)+"<StatementList>\n";
    for(int j=0;j<Statements->size();j++){
        re+=Helper::GetElementStatementNode(Statements,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementList>\n";

    re+=Helper::GetIdentation(i)+"</StatementMientras>\n";
    return re;
}


void StatementMientrasNode::ValidateSemantic()
{
    if(Expression->ValidateSemantic()->Name!="Booleano")
    {
        throw SemanticException("Se esperaba Booleano ,Fila:"+to_string(Expression->Row)+",Columna:"+to_string(Expression->Column));
    }
    list<StatementNode*>::const_iterator iterator;
    StatementNode* temp;
    for (iterator = Statements->begin(); iterator != Statements->end(); ++iterator) {
        temp=*iterator;
        temp->ValidateSemantic();
    }
}
