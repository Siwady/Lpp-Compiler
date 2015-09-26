#include "lppprogram.h"
#include "../helper.h"

LppProgram::~LppProgram()
{
	delete Header;
	delete Statements;
}

void LppProgram::Interpret()
{
	Header->Interpret();
	for (int i = 0; i < Statements->size(); i++)
	{
		Helper::GetElementStatementNode(Statements, i)->Interpret();
	}
}

LppProgram::LppProgram(ProgramHeaderNode *program, list<StatementNode *> *ls, int row, int column)
{
    this->Header=program;
    this->Statements=ls;
    this->Row=row;
    this->Column=column;
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



void LppProgram::ValidateSemantic()
{
    //falta
	Header->ValidateSemantic();
    list<StatementNode*>::const_iterator iterator;
    StatementNode *e;
    for (iterator = Statements->begin(); iterator != Statements->end(); ++iterator) {
        e=*iterator;
        e->ValidateSemantic();
    }
}
