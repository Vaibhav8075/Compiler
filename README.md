# Java-Safe C++

Java-Safe C++ is a fully functional compiler and virtual machine designed to execute a restricted subset of C++ with strict memory safety guarantees.

## Motivation

C++ is a powerful language, but it notoriously lacks memory safety, often leading to undefined behavior, buffer overflows, and null pointer dereferences. The goal of this project is to demonstrate how a compiler can integrate memory safety mechanisms directly into its pipeline and target a custom VM, effectively making a subset of C++ as memory-safe as Java.

## Design Goals

- **No Undefined Behavior**: Supported unsafe operations result in graceful runtime exceptions.
- **Genuine Implementation**: Built from scratch without external dependencies like LLVM or Lex/Yacc.
- **Understandable Architecture**: Clear compiler phases implemented in standard C++17.

## Architecture Pipeline

The compiler follows a classic multi-stage pipeline:
1. **Lexer**: Tokenizes raw source code and tracks precise line/column information for diagnostics.
2. **Parser**: Hand-written recursive-descent parser that constructs a custom Abstract Syntax Tree (AST).
3. **Semantic Analyzer**: Enforces static typing, variable scoping, and function resolution.
4. **Code Generator**: Lowers the AST into our custom bytecode and seamlessly injects memory safety opcodes (`CHECK_NULL`, `CHECK_BOUNDS`, `INC_REF`, `DEC_REF`).
5. **Virtual Machine**: A stack-based runtime engine equipped with an Operand Stack, Call Stack, and a Managed Heap.

## Supported Language Subset

The compiler supports a subset of C++ including:
- Variables (`int`, `bool`, pointers, arrays)
- Control flow (`if`, `while`, `for`, `return`)
- Functions
- Pointer arithmetic and dereferencing (`*p`, `new`)
- Array indexing (`arr[i]`)

## Safety Mechanisms

The compiler enforces safety by injecting checks during code generation:
1. **Null Pointer Checks**: Generates `CHECK_NULL` before pointer dereferences.
2. **Array Bounds Checks**: Generates `CHECK_BOUNDS` before array accesses.
3. **Automatic Reference Counting (ARC)**: Tracks dynamic allocations (`new`) and reclaims them safely.

## Build Instructions

Requirements:
- C++17 compiler
- CMake 3.15+

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Usage

```bash
# Compile and run
./jscpp run ../examples/hello.cppsafe

# Trace execution
./jscpp run ../examples/arrays.cppsafe --trace

# Dump bytecode
./jscpp compile ../examples/pointers.cppsafe -o pointers.jbc
./jscpp dump pointers.jbc
```

## Supported Language Subset & Limitations

This compiler is designed as a proof-of-concept for memory-safe execution. It strictly supports a **minimal subset of C++** (basic primitives, pointers, arrays, loops, and functions). 

**Explicit Exclusions:**
This project explicitly excludes advanced C++ features. The compiler will deliberately reject the following with specific error messages:
- Templates
- Classes and Structs
- The Standard Template Library (STL)
- Preprocessor macros (e.g., `#include`, `#define`)
- Multiple inheritance and object-oriented features

By restricting the language subset, we guarantee absolute memory safety (null checking, bounds checking, ARC) without the overhead of tracking complex C++ memory semantics.

- **Cyclic References**: The reference counting implementation does not inherently solve cyclic ownership.
- **Performance**: The VM interprets custom bytecode and prioritizes safety over execution speed.
