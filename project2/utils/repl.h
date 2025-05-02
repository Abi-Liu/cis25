//
// Created by Abi Liu on 4/27/25.
//
#include "person.h"
#ifndef REPL_H
#define REPL_H



namespace ReplNamespace {
    enum Command {
      Add = 1,
      Delete,
      SearchName,
      SearchNumber,
      Print,
      Exit,
      Unknown,
    };

    void start();
    int getCommand();
    std::string getLineInput(const std::string&);
    Command parseCommand(const int&);
    PersonNamespace::Person getPersonDetail();
}




#endif //REPL_H
