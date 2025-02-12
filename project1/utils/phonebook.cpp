//
// Created by Abi Liu on 2/11/25.
//

#include <iostream>
#include <map>
#include "phonebook.h"
#include "person.h"
using namespace PersonNamespace;
using namespace std;

// later we can modify this function to load a list of contacts from a text file
map<string, Person> createPhonebook() {
  map<string, Person> phonebook;
  return phonebook;
}


void printContacts(){}

// for later projects I will add input validation for phoneNumbers
bool addContact(map<string, Person>& phonebook, const string& phoneNumber, Person& person){
  // first we search to see if the phone number already exists
  if(phonebook.find(phoneNumber) == phonebook.end()){
    // phonenumber does not exist, add and return true
    phonebook[phoneNumber] = person;
    return true;
  }

  // this phone number already exists, do not modify the map and return false;
  return false;
}

bool deleteContact(){}
bool updateContact(){}

Person search(const string& phoneNumber){

}
