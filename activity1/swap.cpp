//
// Created by Abi Liu on 1/22/25.
//
#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int* a, int* b);

int main() {
  int a = 10, b = 20;
  cout << a << " " << b << endl;
  swap(&a, &b);
  cout << a << " " << b << endl;
}

void swap(int* a, int* b) {
  std::cout << "Swapping values " << a << " and " << b << std::endl;
  int temp = *a;
  *a = *b;
  *b = temp;
  std::cout << "a: " << *a << " b: " << *b << std::endl;
}
