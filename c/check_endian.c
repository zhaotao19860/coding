// gcc -o check_endian check_endian.c && ./check_endian
#include <stdbool.h> //for bool/false/true
#include <stdint.h>  //for uint16_t/uint8_t
#include <stdio.h>   //for printf

typedef union {
  uint16_t num;
  uint8_t byte[2];
} endian_t;

bool is_big_endian(void) {
  endian_t x;
  x.num = 1; // 0x0001
  if (x.byte[0] == 0)
    return true;
  else
    return false;
}

int main(void) {
  bool rc;
  rc = is_big_endian();
  if (rc == true)
    printf("system is big endian;\n");
  else
    printf("system is little endian;\n");
  return 0;
}