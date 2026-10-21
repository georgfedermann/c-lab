# C Fundamentals
*One man's constant is another man's variable.*

Read `&height` as "Address of height".

## Using Directives
```c
// Include c libraries
#include <stdio.h>
#include <math.h>

// Define constants
#define INCHES_PER_POUND 166
```

## Compiling a C program
```bash
# Simple compiling with limited or no optimizations and lots of warnings
gcc -O -Wall -W -pedantic -ansi -std=c99 -o <executable> source.c
# or
gcc -std=c99 -Wall -Wextra -Wpedantic -O0 -g -o program source.c

# Stop after pre processor run
gcc -E pun.c

# Stop at assembly output
```
Supported values for the `-std=` flag:
- c90
- c99
- c11
- c17

## Keywords
- auto
- break
- case
- char
- const
- continue
- default
- do
- double
- else
- enum
- extern
- float
- for
- goto
- if
- inline
- int
  - Define 32bit integer variable
  - Probably also (int) as cast operator
- long
- register
- restrict
- return
  - return from a function
- short
- signed
- sizeof
- static
- struct
- switch
- typedef
- union
- unsigned
- void
- volatile
- while
- _Bool
- _Complex
- _Imaginary
