#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H


class SymbolTable
{
private:
    static bool InstanceFlag;
    static SymbolTable *Instance;
    SymbolTable();
public:
    static SymbolTable* GetInstance()
    {
        if(! InstanceFlag)
        {
            Instance = new SymbolTable();
           InstanceFlag = true;
           return Instance;
        }
        else
        {
           return Instance;
        }
    }
    ~SymbolTable(){
        InstanceFlag = false;
    }
};

#endif // SYMBOLTABLE_H
