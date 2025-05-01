//
// Created by Abi Liu on 4/27/25.
//

#ifndef REPL_H
#define REPL_H



namespace ReplNamespace {
    enum Command {
      Add = 1,
      Delete,
      Search,
      Print,
      Unknown,
    };

    void start();
    int getCommand();
    Command parseCommand(const int&);
}




#endif //REPL_H
