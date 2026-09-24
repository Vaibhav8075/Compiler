# Safety Model

Java-Safe C++ guarantees memory safety for all executed programs within its language subset.

## 1. Null Checks
Before dereferencing any pointer via `*p`, the compiler injects a `CHECK_NULL` instruction. If the pointer is null (`0`), a `NullPointerException` is thrown, halting the VM gracefully.

## 2. Array Bounds Checks
Before any array access (`arr[i]`), the compiler injects a `CHECK_BOUNDS` instruction. The VM verifies `0 <= i < length`. If the condition fails, an `ArrayIndexOutOfBoundsException` is thrown.

## 3. Automatic Reference Counting (ARC)
The VM maintains a managed heap. All allocations via `new` are assigned a reference count. The compiler automatically injects `INC_REF` when a pointer is assigned or initialized, and `DEC_REF` when local pointers go out of scope or are reassigned. When a reference count reaches 0, the object is immediately reclaimed. `delete` is technically supported as a manual `DEC_REF` but is unnecessary for memory safety.

## 4. Runtime Type Safety
The VM stack operates on a unified `RuntimeValue` (currently unified as an `int` holding values or pointers). Since the compiler performs strict static type checking during Semantic Analysis, invalid type operations (e.g. adding a pointer and a boolean) are rejected at compile time, eliminating undefined behavior.
