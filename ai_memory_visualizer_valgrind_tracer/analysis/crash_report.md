# Crash Report

## Program
crash_example.c

## What happened?
The program crashes with a segmentation fault.

The variable n is initialized to 0.

The function allocate_numbers(n) checks if n <= 0.
Because n is 0, the function returns NULL.

The pointer nums therefore contains NULL.

At line 32, the program executes:

nums[0] = 42;

It tries to write an integer to address 0, which is invalid.

## Valgrind result

Valgrind reports:
- Invalid write of size 4.
- Invalid address: 0x0.
- Location: crash_example.c, line 32.
- Signal: SIGSEGV.

## How to prevent this error?

Check that nums is not NULL before using it:

if (!nums)
    return 1;

## Conclusion

The crash happens because the program uses a NULL pointer without checking it first.
