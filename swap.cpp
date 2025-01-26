//
// Created by Abi Liu on 1/22/25.
//
#include <iostream>

void swap(int a, int b);

int main() {
  int a = 3;
  int b = 1;
  swap(a, b);
}

void swap(int* a, int* b) {
  std::cout << "Swapping values " << a << " and " << b << std::endl;
  int temp = *a;
  *a = *b;
  *b = temp;
  std::cout << "a: " << a << " b: " << b << std::endl;
}
