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
    LppProgram(ProgramHeaderNode* program, list<StatementNode*>* ls,int row,int column);
    virtual string ToXML(int i);

    // ProgramCodeNode interface
public:
    void ValidateSemantic();
};

#endif // LPPPROGRAM_H
