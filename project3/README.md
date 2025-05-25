# Project 3 - Phonebook application

This is a continuation of Project 2. It keeps the same core functionality, but it is now refactored to implement core principles of Object Oriented Programming:
Abstraction, Encapsulation, Inheritance, Polymorphism, and Composition.

This project also introduces the use of std::unique_ptr to ensure that each contact is memory-safe, exclusively owned by the phonebook, and cannot be accidentally shared or modified outside of controlled interfaces.

[Demo video](https://www.youtube.com/watch?v=eG-mAqZqV7o)

## How to run
Follow these steps to build and run the project

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

Once you have successfully built the project you can run executable files:

### Run Program:
`./main`

## Run tests:
`./tests`
