#include "statementsinode.h"
#include "../../Semantic/semanticexception.h"
#include "../../helper.h"

StatementSiNode::StatementSiNode(ExpressionNode *expr, list<StatementNode *> *statementSi, list<StatementNode *> *statementsSino, int row, int column)
{
    this->Expression=expr;
    this->StatementsSi=statementSi;
    this->StatementsSino=statementsSino;
    this->Row=row;
    this->Column=column;
}



string StatementSiNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementSi>\n";

    re+=Expression->ToXML(i+1);
    re+=Helper::GetIdentation(i+1)+"<StatementList>\n";
    for(int j=0;j<StatementsSi->size();j++){
        re+=Helper::GetElementStatementNode(StatementsSi,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementList>\n";

    re+=Helper::GetIdentation(i+1)+"<StatementList>\n";
    for(int j=0;j<StatementsSino->size();j++){
        re+=Helper::GetElementStatementNode(StatementsSino,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementList>\n";

    re+=Helper::GetIdentation(i)+"</StatementSi>\n";
    return re;
}


void StatementSiNode::ValidateSemantic()
{
    if(Expression->ValidateSemantic()->Name!="Booleano")
    {
        throw SemanticException("Se esperaba Booleano ,Fila:"+to_string(Expression->Row)+",Columna:"+to_string(Expression->Column));
    }

    list<StatementNode*>::const_iterator iterator;
    StatementNode* temp;
    for (iterator = StatementsSi->begin(); iterator != StatementsSi->end(); ++iterator) {
        temp=*iterator;
        temp->ValidateSemantic();
    }

    list<StatementNode*>::const_iterator iterator2;
    for (iterator2 = StatementsSino->begin(); iterator2 != StatementsSino->end(); ++iterator2) {
        temp=*iterator2;
        temp->ValidateSemantic();
    }
}
