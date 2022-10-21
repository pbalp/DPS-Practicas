#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h> 
#include <stddef.h>
#include <inttypes.h>

extern size_t popcount(uintmax_t);
#define PRECISION(x) popcount(x)

size_t popcount(uintmax_t num) {
  size_t precision = 0;
  while (num != 0) {
    if (num % 2 == 1) {
      precision++;
    }
    num >>= 1;
  }
  return precision;
}

unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  if (ui_a==UINT_MAX || ui_b==UINT_MAX) {
    /*
     * INT30-C: Ensure that unsigned integer operations do not wrap
     * INT32-C: Ensure that operations on signed integers do not result in overflow
    */
    printf("ERROR: Maximo Integer permitido");
    return -1;
  }
  unsigned int usum = ui_a + ui_b;
  return usum;
}

unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  if (ui_a==UINT_MAX || ui_b==UINT_MAX) {
    /*
     * INT30-C: Ensure that unsigned integer operations do not wrap
     * INT32-C: Ensure that operations on signed integers do not result in overflow
    */
    printf("ERROR: Maximo Integer permitido");
    return -1;
  }
  unsigned umul = ui_a;
  umul *= ui_b;
  return umul;
}

uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {
  if (ui_a >= PRECISION(UINT_MAX) || ui_b >= PRECISION(UINT_MAX)) {
    /*
     * INT30-C: Ensure that unsigned integer operations do not wrap
     * INT32-C: Ensure that operations on signed integers do not result in overflow
    */
    printf("ERROR: Maximo Integer permitido");
    return -1;
  }
  uint32_t uShift = ui_a << ui_b | ui_a >> (32 - ui_b); 
  return uShift;
}
