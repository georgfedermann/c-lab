#include <stdio.h>

int add_one(int x) {
  return x + 1;
}

int main(void) {
  int x = 0, y = 0;
  for (x = 0; x < 9; x++){
    y = add_one(y);
    printf("Step %d, value %d\n", x, y);
  }

  return 0;
}
