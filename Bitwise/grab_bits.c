#include <stdio.h>
#include <stdint.h>

uint32_t grab_three_bits(uint32_t input, int start_bit)
{
    uint32_t res;
    if(start_bit>=0 && start_bit<=29)
    {
        res= (input >> start_bit) & 7;
        return res;
    }
    else
    {
        return 0xFFFFFFFF;
    }
}
