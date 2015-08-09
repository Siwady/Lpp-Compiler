#ifndef PARSEREXCEPTION_H
#define PARSEREXCEPTION_H

#include <iostream>
#include <exception>
using namespace std;

class ParserException:public exception
{
public:
    string Message;
    ParserException(string message="Parser Exception") : Message(message) {}

    ~ParserException() throw () {}
    const char* what() const throw() { return Message.c_str();}

};

#endif // PARSEREXCEPTION_H
