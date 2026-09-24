# Java-Safe C++ Language Specification

Java-Safe C++ supports a minimal C++ subset tailored for memory safety demonstration.

## Supported Types
- `int`: 32-bit integer.
- `bool`: boolean (`true` or `false`).
- `void`: used for function return types only.
- Pointers: `T*` (e.g., `int*`).
- Arrays: `T[N]` (e.g., `int arr[5]`).

## Control Flow
- `if` / `else`
- `while`
- `for`
- `return`

## Expressions
- Arithmetic: `+`, `-`, `*`, `/`, `%`
- Relational: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Logical: `&&`, `||`, `!`
- Array Indexing: `arr[i]`
- Pointer Dereference: `*p`
- Dynamic Allocation: `new T`

## Built-ins
- `print(int)`: Prints an integer to standard output.

## Unsupported Features
- Classes, structs, templates, exceptions (in source language), multiple inheritance, operator overloading, standard library (STL).
