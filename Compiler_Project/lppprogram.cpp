#include "lppprogram.h"

LppProgram::LppProgram(ProgramHeaderNode *program, list<StatementNode *> *ls)
{
    this->Header=program;
    this->Statements=ls;
}

string LppProgram::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<LppProgram>\n";
    re+=Header->ToXML(i+1);
    re+=Helper::GetIdentation(i+1)+"<StatementList>\n";
    for(int j=0;j<Statements->size();j++){
        re+=Helper::GetElementStatementNode(Statements,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementList>\n";


    re+=Helper::GetIdentation(i)+"</LppProgram>\n";
    return re;
}

