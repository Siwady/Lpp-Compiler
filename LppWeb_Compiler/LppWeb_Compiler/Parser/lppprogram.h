#ifndef LPPPROGRAM_H
#define LPPPROGRAM_H
#include "programcodenode.h"

#include <list>
#include "Header/programheadernode.h"
#include "Statements/statementnode.h"
using namespace std;

class LppProgram: public ProgramCodeNode
{
public:
    ProgramHeaderNode* Header;
    list<StatementNode*>* Statements;
    LppProgram(ProgramHeaderNode* program, list<StatementNode*>* ls,int row,int column);
    virtual string ToXML(int i) override;
    void ValidateSemantic() override;
};

#endif // LPPPROGRAM_H
