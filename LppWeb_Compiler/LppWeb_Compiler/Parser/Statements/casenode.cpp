#include "casenode.h"
#include "../../Semantic/semanticexception.h"
#include "../../helper.h"

CaseNode::CaseNode(list<LiteralNode *> *literals, list<StatementNode *> *statement, int row, int column)
{
    this->Literals=literals;
    this->Statements=statement;
    this->Row=row;
    this->Column=column;
}

string CaseNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<CaseNode>\n";
    re+=Helper::GetIdentation(i+1)+"<LiteralNodeList>\n";
    for(int j=0;j<Literals->size();j++){
        re+=Helper::GetElementLiteralNode(Literals,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</LiteralNodeList>\n";

    re+=Helper::GetIdentation(i+1)+"<StatementNodeList>\n";
    for(int j=0;j<Statements->size();j++){
        re+=Helper::GetElementStatementNode(Statements,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementNodeList>\n";
    re+=Helper::GetIdentation(i)+"</CaseNode>\n";

    return re ;
}

Type *CaseNode::ValidateSemantic()
{
    Type* t=Helper::GetElementLiteralNode(Literals,0)->ValidateSemantic();
    for(int i=1;i<Literals->size();i++)
    {
        if(t->Name.compare(Helper::GetElementLiteralNode(Literals,i)->ValidateSemantic()->Name)!=0)
        {
            throw SemanticException("Se esperaba tipo de dato "+t->Name+",Fila:"+to_string(Helper::GetElementLiteralNode(Literals,i)->Row)+",Columna:"+to_string(Helper::GetElementLiteralNode(Literals,i)->Column));
        }
    }

	for (int j = 0; j < Statements->size(); j++)
	{
		Helper::GetElementStatementNode(Statements, j)->ValidateSemantic();
	}
	return t;
}

