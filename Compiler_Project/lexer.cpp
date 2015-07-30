#include "lexer.h"


Lexer::Lexer(string input)
{
    this->Column=0;
    this->Row=0;
    this->Position=0;
    this->Symbol='\0';
    this->Input=input;
    this->isHtml=true;
    InitializeReservedWords();
    InitializePunctualSymbols();
}

Lexer::Lexer()
{
    this->Column=0;
    this->Row=0;
    this->Position=0;
    this->Symbol='\0';
    this->isHtml=true;
    InitializeReservedWords();
    InitializePunctualSymbols();
}

Lexer::~Lexer()
{

}

Token *Lexer::GetToken()
{
    if(isHtml)
        return GetHTMLToken();
    else
        return GetLppToken();
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

    /*if(currentSymbol=='\n'){
        this->Row++;
        this->Column=0;
    }else{*/
        this->Column++;
    //}

    return currentSymbol;
}

bool Lexer::Contains(Map maps, string lexeme)
{
    auto search=maps.find(lexeme);

    if(search!=maps.end())
    {
        return true;
    }
    return false;
}

Token *Lexer::GetHTMLToken()
{
    int state=0;
    char symbol =GetCurrentSymbol();
    string lexeme = "";
    int column =this->Column;
    int row=this->Row;
    Token * token=new Token();

    while(true){
        switch (state) {
            case 0:
                if(symbol=='<')
                {
                    token->Lexeme+=symbol;
                    symbol=GetNextSymbol();
                    state=1;
                }else if(symbol=='\n')
                {

                    token->Lexeme+=symbol;
                    this->Row++;
                    this->Column=-1;
                    column=0;
                    symbol=GetNextSymbol();
                }
                else if(symbol!='\0')
                {
                    token->Lexeme+=symbol;
                    lexeme+=symbol;
                    symbol=GetNextSymbol();
                    state=2;
                }

                else
                {
                    token->Type=Eof;
                    token->Column=0;
                    token->Lexeme="\0";
                    token->Row=0;
                    return token;
                }

                break;

            case 1:
                if(symbol=='%')
                {
                    token->Lexeme=lexeme;
                    token->Column=column;
                    token->Type=Html;
                    token->Row=row;
                    symbol=GetNextSymbol();
                    //this->Column--;
                    this->isHtml=false;
                    if(token->Lexeme.compare("")==0)
                    {
                        return GetToken();
                    }else
                        return token;
                }else if(symbol=='\0')
                {
                    token->Column=column;
                    token->Type=Html;
                    token->Row=row;
                    this->isHtml=false;
                    return token;
                }else
                {
                    token->Lexeme+=symbol;
                    lexeme=token->Lexeme;
                    symbol=GetNextSymbol();
                    state=2;
                }
                break;
            case 2:
                if(symbol=='<')
                {
                    token->Lexeme+=symbol;
                    symbol=GetNextSymbol();
                    state=1;
                }else if(symbol=='\0')
                {
                    token->Column=column;
                    token->Type=Html;
                    token->Row=row;
                    this->isHtml=false;
                    return token;
                }else if(symbol=='\n')
                {
                    token->Lexeme+=symbol;
                    this->Row++;
                    this->Column=-1;
                    column=0;
                    symbol=GetNextSymbol();
                }
                else
                {
                    token->Lexeme+=symbol;
                    lexeme+=symbol;
                    symbol=GetNextSymbol();
                }
                break;
        }
    }
}

Token *Lexer::GetLppToken()
{
    int state=4;
    char symbol = GetCurrentSymbol();
    string lexeme = "";
    int column =this->Column;
    Token * token=new Token();

    while(true){
        switch (state) {
            case 4:
                if(symbol=='\0'){
                    token->Type=Eof;
                    token->Column=0;
                    token->Lexeme="\0";
                    token->Row=0;

                    return token;
                }else if(symbol=='\n')
                {
                    this->Row++;
                    this->Column=-1;
                    column=0;
                    symbol=GetNextSymbol();

                }
                else if(isdigit(symbol)){

                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 5;
                }
                else if(isalpha(symbol) || symbol=='_')
                {
                    token->Lexeme+=symbol;
                    symbol=GetNextSymbol();
                    state = 8;

                }else if(symbol=='"')
                {
                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 9;
                }else if(symbol=='\'')
                {
                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 11;
                }else if(symbol=='<')
                {
                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 14;
                }else if(symbol=='/')
                {
                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 18;
                }else if(symbol=='>')
                {
                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 16;
                }else if(symbol=='%')
                {
                    lexeme=token->Lexeme;
                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 22;
                }
                else if(Contains(this->PunctualSymbols,string(1,symbol)))
                {

                    token->Type=PunctualSymbols[string(1,symbol)];
                    token->Column=column;
                    token->Row=this->Row;
                    token->Lexeme=symbol;
                    symbol = GetNextSymbol();


                    return token;
                }
                else if(isspace(symbol)){

                    symbol = GetNextSymbol();
                    column=this->Column;
                }else
                {
                    throw LexicalException("Invalid Symbol");
                }
                break;

            case 5:
                if(isdigit(symbol))
                {
                    token->Lexeme += symbol;
                    symbol = GetNextSymbol();
                }else if(symbol=='.')
                {
                    token->Lexeme += symbol;
                    symbol = GetNextSymbol();
                    state = 6;
                }
                else{
                    token->Type=Const_entero;
                    token->Column=column;
                    token->Row=this->Row;
                    return token;
                }
                break;
            case 6:
                if (isdigit(symbol))
                {
                    token->Lexeme += symbol;
                    symbol = GetNextSymbol();
                    state = 7;
                }
                else
                    throw LexicalException("Se esperaba digito");
                break;

            case 7:
                if (isdigit(symbol))
                {
                    token->Lexeme+= symbol;

                    symbol = GetNextSymbol();
                }
                else{
                    token->Type=Const_real;
                    token->Column=column;
                    token->Row=this->Row;
                    return token;
                }
                break;

            case 8:
                if (isdigit(symbol) || isalpha(symbol) || symbol=='_')
                {
                    token->Lexeme+= symbol;
                    token->Type=Id;
                    token->Column=column;
                    symbol = GetNextSymbol();
                }
                else{
                    token->Type=Id;
                    token->Column=column;
                    token->Row=this->Row;

                    if(Contains(this->ReserverdWords,ToLowerCase(token->Lexeme)))
                    {
                        token->Type=ReserverdWords[ToLowerCase(token->Lexeme)];
                    }
                    return token;
                }
                break;

            case 9:
                if(symbol=='"')
                {
                    token->Lexeme += symbol;
                    symbol = GetNextSymbol();
                    state = 10;
                }else if(symbol!='\0')
                {
                    token->Lexeme+= symbol;
                    token->Type=cadena;
                    symbol = GetNextSymbol();
                }else
                {
                    throw LexicalException("se esperaba \" ");
                }
                break;

            case 10:
                token->Type=Const_cadena;
                token->Column=column;
                token->Row=this->Row;
                return token;
                break;

            case 11:

                if(symbol=='\'' || symbol=='\0')
                {
                    throw LexicalException("se esperaba un caracter");
                }else
                {
                    token->Lexeme += symbol;
                    symbol = GetNextSymbol();
                    state = 12;
                }
                break;

            case 12:
                if(symbol=='\'')
                {
                    token->Lexeme += symbol;
                    state = 13;
                }else{
                    throw LexicalException("se esperaba ' ");
                }
                break;

            case 13:
                token->Type=Const_caracter;
                token->Column=column;
                token->Row=this->Row;
                symbol = GetNextSymbol();
                return token;
                break;

            case 14:
                if(symbol=='=' || symbol=='-')
                {
                    token->Lexeme += symbol;
                    //symbol = GetNextSymbol();
                    state = 15;
                }else if(symbol=='>')
                {

                    token->Lexeme+=symbol;
                    token->Column=column;
                    token->Row=this->Row;
                    token->Type=Op_NotEqual;
                    symbol = GetNextSymbol();
                    return token;

                }else
                {
                    token->Type=Op_LessThan;
                    token->Column=column;
                    token->Row=this->Row;
                    symbol = GetNextSymbol();
                    return token;
                }
                break;

            case 15:
                if(symbol=='=' )
                {
                    token->Type=Op_LessOrEqualThan;
                    token->Column=column;
                    token->Row=this->Row;
                    symbol=GetNextSymbol();
                    return token;
                }else
                {
                    token->Type=Op_Assignment;
                    token->Column=column;
                    token->Row=this->Row;
                    symbol=GetNextSymbol();
                    return token;
                }
                break;

            case 16:
                if(symbol=='=')
                {
                    token->Lexeme += symbol;
                    symbol = GetNextSymbol();
                    state = 17;
                }else
                {
                    token->Type=Op_GreaterThan;
                    token->Column=column;
                    token->Row=this->Row;
                    symbol=GetNextSymbol();
                    return token;
                }
                break;

            case 17:
                token->Type=Op_GreaterOrEqualThan;
                token->Column=column;
                token->Row=this->Row;
                return token;
                break;

            case 18:

                if(symbol=='/')
                {
                    token->Lexeme=lexeme;
                    symbol = GetNextSymbol();
                    state = 19;
                }else if(symbol=='*')
                {
                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 20;
                }else
                {
                    token->Type=Op_Div;
                    token->Column=column;
                    token->Row=this->Row;
                    return token;
                }
                break;
//comentarios
            case 19:
                if(symbol=='\n')
                {
                    token->Lexeme="";
                    this->Column=-1;
                    column=0;
                    symbol = GetNextSymbol();
                    state = 4;
                }else if(symbol!='\0')
                {
                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                }else
                {
                    token->Type=Eof;
                    token->Column=0;
                    token->Lexeme="\0";
                    token->Row=0;

                    return token;
                }
                break;

            case 20:
                if(symbol=='*')
                {
                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 21;
                }else if(symbol!='\0')
                {
                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                }else
                {
                    throw LexicalException("se esperaba *");
                }
                break;

            case 21:
                if(symbol=='/')
                {
                    token->Lexeme="";
                    symbol = GetNextSymbol();
                    state=4;
                }else if(symbol!='\0')
                {
                    token->Lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 20;
                }else
                {
                    throw LexicalException("se esperaba /");
                }
                break;

            case 22:
                if(symbol=='>')
                {
                    symbol = GetNextSymbol();
                    isHtml=true;
                    return GetToken();
                }else
                {
                    throw LexicalException("se esperaba >");
                }
                break;

        }
    }
    return token;
}

string Lexer::ToLowerCase(string word)
{
    int i=0;
    char c;
    string newWord="";
    while(word[i])
    {
        c=word[i];
        newWord+=tolower(c);
        i++;
    }
    return newWord;
}

void Lexer::InitializeReservedWords()
{
    this->ReserverdWords.insert(make_pair("id",Id));
    this->ReserverdWords.insert(make_pair("inicio",inicio));
    this->ReserverdWords.insert(make_pair("fin",fin));
    this->ReserverdWords.insert(make_pair("llamar",llamar));
    this->ReserverdWords.insert(make_pair("entero",entero));
    this->ReserverdWords.insert(make_pair("real",real));
    this->ReserverdWords.insert(make_pair("caracter",caracter));
    this->ReserverdWords.insert(make_pair("booleano",booleano));
    this->ReserverdWords.insert(make_pair("cadena",cadena));
    this->ReserverdWords.insert(make_pair("si",si));
    this->ReserverdWords.insert(make_pair("sino",sino));
    this->ReserverdWords.insert(make_pair("caso",caso));
    this->ReserverdWords.insert(make_pair("mientras",mientras));
    this->ReserverdWords.insert(make_pair("para",para));
    this->ReserverdWords.insert(make_pair("hasta",hasta));
    this->ReserverdWords.insert(make_pair("haga",haga));
    this->ReserverdWords.insert(make_pair("repita",repita));
    this->ReserverdWords.insert(make_pair("procedimiento",procedimiento));
    this->ReserverdWords.insert(make_pair("funcion",funcion));
    this->ReserverdWords.insert(make_pair("retorne",retorne));
    this->ReserverdWords.insert(make_pair("registro",registro));
    this->ReserverdWords.insert(make_pair("arreglo",arreglo));
    this->ReserverdWords.insert(make_pair("de",de));
    this->ReserverdWords.insert(make_pair("tipo",tipo));
    this->ReserverdWords.insert(make_pair("abrir",abrir));
    this->ReserverdWords.insert(make_pair("cerrar",cerrar));
    this->ReserverdWords.insert(make_pair("escribir",escribir));
    this->ReserverdWords.insert(make_pair("verdadero",verdadero));
    this->ReserverdWords.insert(make_pair("falso",falso));
    this->ReserverdWords.insert(make_pair("div",Div));
    this->ReserverdWords.insert(make_pair("mod",mod));
    this->ReserverdWords.insert(make_pair("entonces",entonces));
    this->ReserverdWords.insert(make_pair("escriba",escriba));
    this->ReserverdWords.insert(make_pair("nueva_linea",nueva_linea));
    this->ReserverdWords.insert(make_pair("es",es));
    this->ReserverdWords.insert(make_pair("archivo",archivo));
    this->ReserverdWords.insert(make_pair("secuencial",secuencial));
    this->ReserverdWords.insert(make_pair("como",como));
    this->ReserverdWords.insert(make_pair("lectura",lectura));
    this->ReserverdWords.insert(make_pair("escritura",escritura));
    this->ReserverdWords.insert(make_pair("no",no));
    this->ReserverdWords.insert(make_pair("o",Op_LogicalO));
    this->ReserverdWords.insert(make_pair("y",Op_LogicalY));
}

void Lexer::InitializePunctualSymbols()
{
    this->PunctualSymbols.insert(make_pair("+",Op_Sum));
    this->PunctualSymbols.insert(make_pair("-",Op_Sub));
    this->PunctualSymbols.insert(make_pair("*",Op_Mult));
    this->PunctualSymbols.insert(make_pair("^",Op_Exp));
    this->PunctualSymbols.insert(make_pair("(",LeftParent));
    this->PunctualSymbols.insert(make_pair(")",RightParent));
    this->PunctualSymbols.insert(make_pair("=",Equal));
    this->PunctualSymbols.insert(make_pair(":",colon));
    this->PunctualSymbols.insert(make_pair(",",comma));
    this->PunctualSymbols.insert(make_pair("[",LeftBrackets));
    this->PunctualSymbols.insert(make_pair("]",RightBrackets));
    this->PunctualSymbols.insert(make_pair(".",dot));
}


