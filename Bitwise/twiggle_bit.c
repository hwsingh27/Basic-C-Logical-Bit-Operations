#include <stdio.h>
#include <stdint.h>

#include "twiggle_bit.h"

uint32_t twiggle_bit(uint32_t input, int bit, operation_t operation)
{
    if(bit>=0 && bit<=31)
    {
        uint32_t res;
        if(operation==CLEAR)
        {
            res = input & ~(1<<bit);
        }
        else if(operation==SET)
        {
            res= input | (1<<bit);
        }
        else if(operation==TOGGLE)
        {
            res= input ^ (1<<bit);
        }
        else
        {
            return 0xFFFFFFFF;
        }
        return res;
    }
    else
    {
        return 0xFFFFFFFF;
    }
}
