#ifndef LPPPROGRAM_H
#define LPPPROGRAM_H
#include "Parser/Header/programheadernode.h"
#include "Parser/Statements/statementnode.h"
#include "programcodenode.h"
#include "helper.h"
#include <list>
using namespace std;

class LppProgram: public ProgramCodeNode
{
public:
    ProgramHeaderNode* Header;
    list<StatementNode*>* Statements;
    LppProgram(ProgramHeaderNode* program, list<StatementNode*>* ls);
    virtual string ToXML(int i);
};

#endif // LPPPROGRAM_H
