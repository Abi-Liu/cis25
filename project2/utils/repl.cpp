//
// Created by Abi Liu on 4/27/25.
//

#include "repl.h"
#include "phonebook.h"
#include "person.h"
#include <iostream>
using namespace PhonebookNamespace;
using namespace PersonNamespace;
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
            cout << "Please enter an integer from 1 to 6!" << endl;
          } else {
              return val;
          }
      }
    }

    string getLineInput(const string& prompt) {
        string input;
        cout << prompt;

        // Clear any leftover characters from previous input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        getline(cin, input);
        return input;
    }

    Person getPersonDetail() {
      Person person;
      while(true) {
        person.name = getLineInput("Please enter the person's name: ");
        if(person.name.empty()) {
          break;
        }
        cout << "Name cannot be empty!" << endl;
      }

      while(true) {
        person.phoneNumber = getLineInput("Please enter the person's phone number: ");
        if(!isValid(person.phoneNumber)) {
          break;
        }
        cout << "Invalid phone number!" << endl;
      }
    }

    void start() {
      // initialize phonebook
      Phonebook pb;

      // load phonebook from file if it exists
      pb.loadPhonebook();

      cout << "Welcome to your phone book!" << endl;
      cout << "Commands:" << endl;
      cout << "[1] - Add contact" << endl << "[2] - Delete contact" << endl << "[3] - Search contact by name" << "[4] - Search contact by Number"
          << endl << "[5] - Print contacts" << endl
          << "[6] - Exit" << endl;

      while (true) {
        int command = getCommand();
        Command cmd = parseCommand(command);
        // switch statement to utilize different functions based on the command type
        switch (cmd) {
          case Command::Add:
            Person p = getPersonDetail();
            bool success = pb.addContact(p);
            if (!success) {
              cout << "Add contact failed! Phone number already exists or phone number is invalid!" << endl;
            }
            break;
          case Command::Delete:

        }
      }
    }
}