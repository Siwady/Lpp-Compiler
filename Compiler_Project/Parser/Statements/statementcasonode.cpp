#include "statementcasonode.h"

StatementCasoNode::StatementCasoNode(VariableNode *var, list<CaseNode *> *cases, list<StatementNode *> *sinocase)
{
    this->Variable=var;
    this->Cases=cases;
    this->SinoCase=sinocase;
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
