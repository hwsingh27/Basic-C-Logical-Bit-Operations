#include <stdio.h>
#include <stdint.h>

int conv_to_binstr(char *str, size_t size, uint32_t num, uint8_t nbits)
{
    if(nbits+3>size || nbits==0 || nbits>32)
        return -1;

    char *s = str;
    *s++ = '0';
    *s++ = 'b';

    for(uint32_t mask = 1<<(nbits-1);mask>0;mask>>=1)
    {
        if(num&mask)
            *s++ = '1';
        else
            *s++ = '0';
    }
    *s='\0';
    return nbits+2;
}

int int_to_binstr(char *str, size_t size, int32_t num, uint8_t nbits)
{
    if(str==NULL)
        return -1;
    str[0]='\0';

    const int64_t lim = 1LL << (nbits-1);
    if(num>=lim || -num>lim)
        return -1;

    return conv_to_binstr(str,size,(uint32_t)num,nbits);
}
