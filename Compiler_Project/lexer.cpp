#include "lexer.h"


Lexer::Lexer(string input)
{
    this->Column=0;
    this->Row=0;
    this->Position=0;
    this->Symbol='\0';
    this->Input=input;
    InitializeReservedWords();
}

Lexer::Lexer()
{
    this->Column=0;
    this->Row=0;
    this->Position=0;
    this->Symbol='\0';
    InitializeReservedWords();
}

Lexer::~Lexer()
{

}

Token *Lexer::GetToken()
{
    int state=0;
    char symbol = GetCurrentSymbol();
    string lexeme = "";
    int column =this->Column;
    Token * token=new Token();

    while(true){
        switch (state) {
            case 0:
                if(symbol=='\0'){
                    token->Type=Eof;
                    token->Column=column;
                    token->Lexeme="\0";
                    token->Row=this->Row;

                    return token;
                }
                else if(isdigit(symbol)){
                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 1;
                }
                else if(isalpha(symbol))
                {
                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 4;
                }
                else if(isspace(symbol)){
                    symbol = GetNextSymbol();
                    column=this->Column-1;
                }
                else if(symbol=='\n'){
                    /*symbol = GetNextSymbol();

                    this->Row++;
                    this->Column=column=0;*/
                }
                break;

            case 1:
                if(isdigit(symbol))
                {
                    token->Lexeme += symbol;
                    symbol = GetNextSymbol();
                }else if(symbol=='.')
                {
                    token->Lexeme += symbol;
                    symbol = GetNextSymbol();
                    state = 2;
                }
                else{
                    token->Type=entero;
                    token->Column=column;
                    token->Row=this->Row;
                    return token;
                }
                break;
            case 2:
                if (isdigit(symbol))
                {
                    token->Lexeme += symbol;
                    symbol = GetNextSymbol();
                    state = 3;
                }
                else
                    throw LexicalException("Se esperaba digito");
                break;

            case 3:
                if (isdigit(symbol))
                {
                    token->Lexeme+= symbol;
                    token->Type=real;
                    token->Column=column;
                    token->Row=this->Row;
                    symbol = GetNextSymbol();
                }
                else
                    return token;
                break;

            case 4:
                if (isdigit(symbol) || isalpha(symbol))
                {
                    token->Lexeme+= symbol;
                    token->Type=Id;
                    symbol = GetNextSymbol();
                }
                else{
                    token->Type=Id;
                    token->Column=column;
                    token->Row=this->Row;
                    if(Contains(token->Lexeme))
                    {
                        token->Type=ReserverdWords.at(token->Lexeme);
                    }
                    return token;
                }
                break;

        }
    }
    return token;
}

char Lexer::GetCurrentSymbol()
{
    if(this->Position<this->Input.size())
    {
        return Input.at(this->Position);
    }
    return '\0';
}

char Lexer::GetNextSymbol()
{
    this->Position++;
    char currentSymbol=GetCurrentSymbol();

    if(currentSymbol=='\n'){
        this->Row++;
        this->Column=0;

    }else{
        this->Column++;
    }

    return currentSymbol;
}

void Lexer::InitializeReservedWords()
{
    this->ReserverdWords.insert(make_pair("id",Id));
    this->ReserverdWords.insert(make_pair("inicio",inicio));
    this->ReserverdWords.insert(make_pair("fin",fin));
    this->ReserverdWords.insert(make_pair("escriba",escriba));
}

bool Lexer::Contains(string lexeme)
{
    auto search=this->ReserverdWords.find(lexeme);

    if(search!=this->ReserverdWords.end())
    {
        return true;
    }
    return false;
}


