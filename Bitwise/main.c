#include <stdio.h>
#include <stdint.h>

#include "test.h"

int main()
{
    test_uint_binstr();
    test_int_binstr();
    test_twiggle_bit();
    test_grab_bits();
    test_hexdump();
    return 0;
}
