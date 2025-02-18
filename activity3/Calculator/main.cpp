//
// Created by Abi Liu on 1/29/25.
//
#include <iostream>
using namespace std;

int getInt() {
  int num;
  while (true) {
    cin >> num;


    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter an integer.\n";
    } else {
      return num;
    }
  }

}

int main() {
  char op;
  cout << "Select an operator:" << " +, -, *, /" << endl;
  cin >> op;
  cout << "Enter two numbers:" << endl;
  int num1 = getInt();
  int num2 = getInt();
  switch (op) {
    case '+':
      cout << num1 + num2 << endl;
      break;
    case '-':
      cout << num1 - num2 << endl;
      break;
    case '*':
      cout << num1 * num2 << endl;
      break;
    case '/':
      if(num2 == 0) {
        cout << "Error! Division by zero!" << endl;
        break;
      }
      cout << num1 / num2 << endl;
      break;
    default:
      cout << "Invalid operator! Please try again";
  }
    return 0;
}