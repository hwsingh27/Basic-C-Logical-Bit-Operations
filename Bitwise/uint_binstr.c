#include <stdio.h>
#include <stdint.h>

int uint_to_binstr(char *str, size_t size, int32_t num, uint8_t nbits)
{
    if(str==NULL)
        return -1;
    if(num>=(1<<nbits) || nbits+3>size || nbits==0 || nbits>32)
    {
        str[0]='\0';
        return -1;
    }
    char *s=str;
    *s++ = '0';
    *s++ = 'b';

    for(uint32_t mask = 1<<(nbits-1);mask>0;mask>>=1)
    {
        if(num & mask)
            *s++ = '1';
        else
            *s++ = '0';
    }
    *s = '\0';
    return nbits+2;
}
