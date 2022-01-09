#ifndef HEXDUMP_H_INCLUDED
#define HEXDUMP_H_INCLUDED

char conv_to_hex(uint16_t num);
char *hexdump(char *str, size_t size, const void *loc, size_t nbytes);

#endif // HEXDUMP_H_INCLUDED
