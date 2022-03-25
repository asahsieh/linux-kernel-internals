#include <stdio.h>

int main (int argc, char *argv[]) {
  size_t *iPtr = 0;              // A pointer to int, initialized with 0.
  size_t iArray[] = {0, 10, 20}; // An array of int, initialized.

  iPtr = iArray;
  size_t *last_ele_ptr =
      (size_t *)((size_t)iPtr + (sizeof(iArray) / sizeof(size_t)) - 1);

  printf("(Original) The array starts at the address %p.\n", iPtr);
  printf("(from lab0-c) The address of (size_t)iPtr is 0x%lx.\n", (size_t)iPtr);
  printf("(from lab0-c) The address of last_ele_ptr is %p.\n", last_ele_ptr);
  printf("(from lab0-c) The last element of the array is 0x%lx.\n\n",
         *last_ele_ptr);

  int array_length = sizeof(iArray) / sizeof(size_t); // The number of elements:
                                                      // in this case, 3.

  // Forward the message for comparing start addresses on different
  // implementations
  //
  // printf("(Original) The array starts at the address %p.\n", iArray);

  *iArray = 5; // Equivalent to iArray[0] = 5;

  iPtr = iArray + array_length - 1; // Point to the last element of iArray:
                                    // Equivalent to
                                    // iPtr = &iArray[array_length-1];
                                    //

  printf("(Original) The address of iPtr is %p.\n", iPtr);
  printf("(Original) The last element of the array is %lu.\n", *iPtr);
}
