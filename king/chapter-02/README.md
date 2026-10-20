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

# Stop at assembly output
```
