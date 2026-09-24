# Bytecode Specification

The VM uses a custom, portable stack-based instruction set.

## Opcodes

| Opcode | Operand | Effect / Purpose |
|--------|---------|------------------|
| `PUSH_CONST` | index | Pushes constant from Constant Table at `index` onto stack. |
| `LOAD_LOCAL` | index | Loads local variable at `index` onto stack. |
| `STORE_LOCAL`| index | Pops value from stack and stores it in local variable `index`. |
| `ADD`, `SUB`, `MUL`, `DIV`, `MOD` | None | Pops two values, computes result, pushes result. |
| `EQ`, `NE`, `LT`, `GT`, `LE`, `GE` | None | Pops two values, computes relational result (1/0), pushes result. |
| `AND`, `OR`, `NOT` | None | Logical operations. |
| `JUMP` | offset | Unconditional jump to instruction at `offset`. |
| `JUMP_IF_FALSE` | offset | Pops condition. If false (0), jumps to `offset`. |
| `CALL` | hash | Calls function identified by `hash`. |
| `RETURN` | None | Returns from function, popping frame and pushing return value. |
| `ALLOC` | size | Allocates `size` elements on managed heap, pushes pointer. |
| `INC_REF` | None | Increments ref count of pointer at top of stack. |
| `DEC_REF` | None | Decrements ref count of pointer at top of stack. |
| `LOAD_ARRAY` | None | Pops index, pops array ptr, pushes array[index]. |
| `STORE_ARRAY_INV` | None | Pops index, array ptr, value. Stores value in array[index] and pushes value back. |
| `CHECK_BOUNDS` | None | Peeks array ptr and index. Throws if index is out of bounds. |
| `CHECK_NULL` | None | Peeks pointer. Throws if null. |
| `LOAD_POINTER` | None | Pops pointer, pushes dereferenced value. |
| `STORE_POINTER`| None | Pops value, pops pointer, stores value at pointer, pushes value back. |
| `PRINT` | None | Pops value and prints it. |
| `POP` | None | Pops and discards the top value on the stack. |
| `HALT` | None | Halts VM execution. |
