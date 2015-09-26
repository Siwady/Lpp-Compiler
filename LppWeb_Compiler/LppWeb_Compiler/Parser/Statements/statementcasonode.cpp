#include "statementcasonode.h"
#include "../../Semantic/semanticexception.h"
#include "../../helper.h"

StatementCasoNode::~StatementCasoNode()
{
	delete Variable;
	delete Cases;
	delete SinoCase;
}

void StatementCasoNode::Interpret()
{
	bool def = true;
	Value* var = Variable->Interpret();
	CaseNode* c;
	for (int i = 0; i < Cases->size();i++) {
		c=Helper::GetElementCaseNode(Cases, i);
		for (int j = 0; j < c->Literals->size(); j++){
			if (Helper::CompareValues(Helper::GetElementLiteralNode(c->Literals, j)->Interpret(),var))
			{
				def = false;
				c->Interpret();
			}
		}
	}

	if (def)
	{
		for (int k = 0; k < SinoCase->size(); k++){
			Helper::GetElementStatementNode(SinoCase, k)->Interpret();
		}
	}

	
}

StatementCasoNode::StatementCasoNode(VariableNode *var, list<CaseNode *> *cases, list<StatementNode *> *sinocase, int row, int column)
{
    this->Variable=var;
    this->Cases=cases;
    this->SinoCase=sinocase;
    this->Row=row;
    this->Column=column;
}

string StatementCasoNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementCase>\n";

    re+=Variable->ToXML(i+1);

    re+=Helper::GetIdentation(i+1)+"<CaseList>\n";
    for(int j=0;j<Cases->size();j++){
        re+=Helper::GetElementCaseNode(Cases,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</CaseList>\n";

    re+=Helper::GetIdentation(i+1)+"<StatementList>\n";
    for(int j=0;j<SinoCase->size();j++){
        re+=Helper::GetElementStatementNode(SinoCase,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementList>\n";

    re+=Helper::GetIdentation(i)+"</StatementCase>\n";
    return re;
}


void StatementCasoNode::ValidateSemantic()
{
    Type* var=Variable->ValidateSemantic();

    list<CaseNode*>::const_iterator iterator;
    CaseNode* temp;
    for (iterator = Cases->begin(); iterator != Cases->end(); ++iterator) {
        temp=*iterator;
        if(temp->ValidateSemantic()->Name.compare(var->Name)!=0)
        {
            throw SemanticException("Tipo de dato incompatible,Fila:"+to_string(temp->Row)+",Columna:"+to_string(temp->Column));
        }
    }

    list<StatementNode*>::const_iterator iterator2;
    StatementNode* temp2;
    for (iterator2 = SinoCase->begin(); iterator2 != SinoCase->end(); ++iterator2) {
        temp2=*iterator2;
        temp2->ValidateSemantic();
    }
}
