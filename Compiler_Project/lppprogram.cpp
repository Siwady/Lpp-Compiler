#include "lppprogram.h"

LppProgram::LppProgram(ProgramHeaderNode *program, list<StatementNode *> *ls)
{
    this->Header=program;
    this->Statements=ls;
}

