#ifndef LEXICALEXCEPTION_H
#define LEXICALEXCEPTION_H

#include <iostream>
#include <exception>
using namespace std;

class LexicalException:public exception
{
public:
    string Message;
    LexicalException(string message) : Message(message) {}

    ~LexicalException() throw () {}
    const char* what() const throw() { return Message.c_str();}
};

#endif // LEXICALEXCEPTION_H
