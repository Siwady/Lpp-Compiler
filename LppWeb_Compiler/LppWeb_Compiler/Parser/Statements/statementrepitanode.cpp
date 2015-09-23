#include "statementrepitanode.h"
#include "../../Semantic/semanticexception.h"
#include "../../helper.h"

StatementRepitaNode::StatementRepitaNode(ExpressionNode *expr, list<StatementNode *> *ls, int row, int column)
{
    this->Expression=expr;
    this->Statements=ls;
    this->Row=row;
    this->Column=column;
}



string StatementRepitaNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementRepita>\n";

    re+=Expression->ToXML(i+1);
    re+=Helper::GetIdentation(i+1)+"<StatementList>\n";
    for(int j=0;j<Statements->size();j++){
        re+=Helper::GetElementStatementNode(Statements,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementList>\n";

    re+=Helper::GetIdentation(i)+"</StatementRepita>\n";
    return re;
}


void StatementRepitaNode::ValidateSemantic()
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
