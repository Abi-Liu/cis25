//
// Created by Abi Liu on 4/27/25.
//

#include "repl.h"
#include "phonebook.h"
#include "person.h"
#include <iostream>
#include <vector>
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

    // gets user input commands and ensures the user has inputted a valid command
    int getCommand() {
      int val;
      while(true) {
          cout << "Please enter the number corresponding to the command: ";
          cin >> val;
          if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Please enter an integer from 1 to 6!" << endl;
          } else {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
              return val;
          }
      }
    }

  // helper method to easily getLine input with a prompt
    string getLineInput(const string& prompt) {
        string input;
        cout << prompt;

        getline(cin, input);
        return input;
    }

  // helper method to create Person structs to be added into the phonebook
    Person getPersonDetail() {
      Person person;
      while(true) {
        person.name = getLineInput("Please enter the person's name: ");
        if(!person.name.empty()) {
          break;
        }
        cout << "Name cannot be empty!" << endl;
      }

      while(true) {
        person.phoneNumber = getLineInput("Please enter the person's phone number: ");
        if(isValid(person.phoneNumber)) {
          break;
        }
        cout << "Invalid phone number!" << endl;
      }
      return person;
    }

  // main function to run the REPL
    void start() {
      // initialize phonebook
      Phonebook pb;

      cout << "Welcome to your phone book!" << endl << endl;

      cout << "Loading the phone book..." << endl;
      // load phonebook from file if it exists
      pb = pb.loadPhonebook();

      cout << "Commands:" << endl;
      cout << "[1] - Add contact" << endl << "[2] - Delete contact" << endl << "[3] - Search contact by name" <<endl << "[4] - Search contact by Number"
          << endl << "[5] - Print contacts" << endl
          << "[6] - Exit" << endl;

      while (true) {
        int command = getCommand();
        Command cmd = parseCommand(command);
        // switch statement to utilize different functions based on the command type
        switch (cmd) {
          case Command::Add: {
            Person p = getPersonDetail();
            bool success = pb.addContact(p);
            if (!success) {
              cout << "Add contact failed! Phone number already exists or phone number is invalid!" << endl;
            } else {
              cout << "Added " << p.name << " successfully!" << endl;
            }
            break;
          }
          case Command::Delete: {
            while(true) {
              string number = getLineInput("Please enter the phone number to delete: ");
              if(isValid(number)) {
                bool res = pb.deleteContact(number);
                if (res) {
                  cout << "Deleted contact successfully!" << endl;
                } else {
                  cout << "Contact not found!" << endl;
                }
                break;
              } else {
                cout << "Please enter a valid phone number!" << endl;
              }
            }
            break;
          }

          case Command::SearchName: {
            string name = getLineInput("Please enter the name to search: ");
            vector<Person> res = pb.searchByName(name);

            if (res.empty()) {
              cout << "No contacts found with substring " << name << endl;
            } else {
              // print list of results
              for(Person p : res) {
                p.display();
              }
            }
            break;
          }

          case Command::SearchNumber: {
            while (true) {
              string number = getLineInput("Please enter the number to search: ");
              if(isValid(number)) {
                Person* p = pb.searchByNumber(number);
                if(p) {
                  p->display();
                } else {
                  cout << "Could not find contact for number " << number << endl;
                }
                break;
              } else {
                cout << "Please enter a valid number!" << endl;
              }
            }
            break;
          }

          case Command::Print: {
            pb.printContacts();
            break;
          }

          case Command::Exit: {
            cout << "Saving phonebook..." << endl;
            // save phonebook
            pb.savePhonebook();
            cout << "Goodbye!" << endl;
            return;
          }

          default:
            cout << "Invalid command!" << endl;
        }
      }
    }
}