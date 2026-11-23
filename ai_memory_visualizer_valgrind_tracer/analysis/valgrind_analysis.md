# Valgrind Analysis

## 1. Stack Example

Valgrind result:
- 0 errors
- 0 bytes in use at exit
- No memory leaks

The recursive function uses local variables. Each function call has its own variables, which remain valid until the call returns.

No invalid memory access was detected.

## 2. Heap Example

Valgrind result:
- 5 allocations
- 4 frees
- 6 bytes definitely lost

The problem is in the Alice allocation.

The Person structure is freed, but the separate memory block containing Alice's name is not freed.

This is a memory leak caused by losing the pointer to an allocated block.

Bob is correctly freed.

## 3. Aliasing Example

Valgrind result:
- 3 errors
- 0 memory leaks

The pointers a and b refer to the same allocated array.

After free(a), b still contains the old address.

Valgrind reports:
- Line 42: invalid read (use-after-free).
- Line 44: invalid write (use-after-free).
- Line 45: invalid read (use-after-free).

The memory was already released, but the program continued to use it.

## 4. Crash Example

Valgrind result:
- Invalid write of size 4.
- Invalid address: 0x0.
- Location: line 32.
- Signal: SIGSEGV.

The variable n is 0. The function allocate_numbers returns NULL.

The program then tries to write to nums[0] without checking the pointer.

This causes an invalid write through a NULL pointer.

## 5. AI Review

The AI explanation correctly stated that the value read after free is unpredictable.

In our execution, the program displayed 1404180482. This value does not prove that the memory was overwritten or that the access is valid.

Valgrind reports an invalid read because the memory had already been freed. The result of accessing it is undefined and cannot be relied on.

## Conclusion

Valgrind helped identify three different memory problems:
- Heap memory leak.
- Use-after-free.
- NULL pointer dereference.

The stack example showed no memory errors.

The results were checked against the source code and the memory maps.
