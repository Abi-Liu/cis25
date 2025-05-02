//
// Created by Abi Liu on 4/27/25.
//

#include "repl.h"
#include <iostream>
using namespace std;

namespace ReplNamespace {
    Command parseCommand(const int& cmd) {
        switch (cmd) {
          case 1: return Command::Add;
          case 2: return Command::Delete;
          case 3: return Command::SearchName;
          case 4: return Command::SearchNumber;
          case 5: return Command::Print;
          case 6: return Command::Exit;
          default: return Command::Unknown;
        }
    }

    int getCommand() {
      int val;
      while(true) {
          cout << "Please enter the number corresponding to the command: ";
          cin >> val;
          if(cin.fail()) {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            cout << "Please enter an integer from 1 to 4!" << endl;
          } else {
              return val;
          }
      }
    }

    void start() {
      cout << "Welcome to your phone book!" << endl;
      cout << "Commands:" << endl;
      cout << "[1] - Add contact" << endl << "[2] - Delete contact" << endl << "[3] - Search contact by name" << "[4] - Search contact by Number"
          << endl << "[5] - Print contacts" << endl
          << "[6] - Exit" << endl;
      while (true) {
        getCommand();
      }
    }
}