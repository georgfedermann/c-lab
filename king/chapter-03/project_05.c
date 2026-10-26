// Name: project_05.c
// Purpose: Read the numbers of a 4x4 matrix and check whether it might
//          be a magic square by printing the sums of all columns and
//          rows and the let the user check.
// Author: Georg

#include <stdio.h>

int main(void) {
  // The magic square value matrix
  int i00, i01, i02, i03, i10, i11, i12, i13,
      i20, i21, i22, i23, i30, i31, i32, i33;

  // The row sums
  int row0, row1, row2, row3;
  // The column sums
  int col0, col1, col2, col3;
  // The diagonal sums
  int d0, d1;

  // Verify the user actually entered the expected 16 values as a minimal
  // reconciliation.
  int rv;

  printf("This program asks you to enter the numbers from 1 to 16 in\n");
  printf(
      "a sequence you provide as a solution to a magic square. The software\n");
  printf(
      "will calculate the sums over your numbers for each column and row.\n");
  printf("Enter the 16 numbers now (e.g. 1 3 16 4 9 2 ...): ");
  rv = scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &i00, &i01, &i02, &i03, &i10,
             &i11, &i12, &i13, &i20, &i21, &i22, &i23, &i30, &i31, &i32, &i33);

  if (rv != 16) {
    printf("Tried to read 16 values, scanf returned %d before that.\n", rv);
    return 1;
  }

  row0 = i00 + i01 + i02 + i03;
  row1 = i10 + i11 + i12 + i13;
  row2 = i20 + i21 + i22 + i23;
  row3 = i30 + i31 + i32 + i33;

  col0 = i00 + i10 + i20 + i30;
  col1 = i01 + i11 + i21 + i31;
  col2 = i02 + i12 + i22 + i32;
  col3 = i03 + i13 + i23 + i33;

  d0 = i00 + i11 + i22 + i33;
  d1 = i03 + i12 + i21 + i30;

  printf("Now, is it a magic square?\n");
  printf("%02d %02d %02d %02d | %02d\n", i00, i01, i02, i03, row0);
  printf("%02d %02d %02d %02d | %02d\n", i10, i11, i12, i13, row1);
  printf("%02d %02d %02d %02d | %02d\n", i20, i21, i22, i23, row2);
  printf("%02d %02d %02d %02d | %02d\n", i30, i31, i32, i33, row3);
  printf("------------+---\n");
  printf("%02d %02d %02d %02d\n", col0, col1, col2, col3);
  printf("Diagonal sums: %02d %02d\n", d0, d1);

  return 0;
}
