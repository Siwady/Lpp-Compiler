// LppWeb_Compiler.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <fstream>
#include "Lexer/lexer.h"
#include "Parser/parser.h"
#include "Semantic/semanticexception.h"
#include "helper.h"


int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		ifstream myCode("C:/Users/ESiwady/Documents/UNITEC/CompiladoresI/Lpp-Compiler/Compiler_Project/Code3.txt");
		string code((istreambuf_iterator<char>(myCode)), (istreambuf_iterator<char>()));
		Lexer* lex = new Lexer(code);

		Parser* parser = new Parser(lex);
		list<ProgramCodeNode*>*ls = parser->Parse();
		cout << "Parser Works!!!\n\n";
		ProgramCodeNode *p = new ProgramCodeNode();
		for (int i = 0; i<ls->size(); i++)
		{
			//cout<<Helper::GetElementProgramCodeNode(ls,i)->ToXML(0);
			
			p = Helper::GetElementProgramCodeNode(ls, i);
			p ->ValidateSemantic();
		}
		cout << "Semantic Works!!!\n\n";

		for (int i = 0; i<ls->size(); i++)
		{
			//cout<<Helper::GetElementProgramCodeNode(ls,i)->ToXML(0);
			 Helper::GetElementProgramCodeNode(ls, i)->Interpret();
		}
		
		cin.get();
	}
	catch (LexicalException& e)
	{
		cout << e.what() << '\n';
		cin.get();
	}
	catch (ParserException& e)
	{
		cout << e.what() << '\n';
		cin.get();
	}
	catch (SemanticException& e)
	{
		cout << e.what() << '\n';
		cin.get();
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
		cin.get();
	}
	return 0;
}

