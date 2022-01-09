#ifndef INT_BINSTR_H_INCLUDED
#define INT_BINSTR_H_INCLUDED

#include <stdio.h>
#include <stdint.h>

int conv_to_binstr(char *str, size_t size, uint32_t num, uint8_t nbits);
int int_to_binstr(char *str, size_t size, int32_t num, uint8_t nbits);

#endif // INT_BINSTR_H_INCLUDED
