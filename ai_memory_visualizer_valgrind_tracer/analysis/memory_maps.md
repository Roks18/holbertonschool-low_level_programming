# Memory Maps

## 1. Stack

Program: stack_example.c

The program uses recursion with walk_stack().

Each function call has its own local variables and its own stack frame.

We observed that:
- Each recursive call has different variable addresses.
- The calls return in reverse order.
- p_local and &local_int have the same address.

Conclusion:
Local variables exist while their function is running. Their lifetime ends when the function returns.

## 2. Heap

Program: heap_example.c

The program creates two Person structures: Alice and Bob.

Each person has:
- A memory block for the Person structure.
- Another memory block for the name.

Bob is correctly freed.

Alice is not completely freed: the structure is released, but the memory for her name is not.

Valgrind result:
- 5 allocations
- 4 frees
- 6 bytes definitely lost

Conclusion:
We must free every allocated memory block.

## 3. Aliasing

Program: aliasing_example.c

The instruction b = a makes both pointers refer to the same memory block.

After free(a), the memory is released, but b still contains the old address.

Using b afterwards causes:
- Invalid read at line 42.
- Invalid write at line 44.
- Invalid read at line 45.

Valgrind detected 3 errors and no memory leaks.

Conclusion:
A pointer must not be used after the memory it points to has been freed.

## 4. AI Review and Correction

The AI explanation suggested that stack addresses always decrease during recursive calls.

This is not guaranteed by the C language. We only observed decreasing addresses during our execution.

Correction:
The addresses depend on the compiler and system. The important point is that each recursive call has its own local variables and lifetime.
