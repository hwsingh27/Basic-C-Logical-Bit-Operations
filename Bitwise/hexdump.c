#include <stdio.h>
#include <stdint.h>

char conv_to_hex(uint16_t num)
{
    if(num>=0 && num<10)
        return '0'+num;
    else if(num>=10 && num<=16)
        return 'A'+num-10;
}

char *hexdump(char *str, size_t size, const void *loc, size_t nbytes)
{
    if(str==NULL)
        return NULL;

    char *s=str;
    const uint8_t *buf = (const uint8_t*) loc;
    *s='\0';

    if(size<(nbytes/16+1)*9+nbytes*3+1)
        return str;

    if(nbytes>=0x10000)
        return str;

    for(int i=0;i<nbytes;i+=16)
    {
        *s++ = '0';
        *s++ = 'x';
        *s++ = conv_to_hex((i&0xF000)>>12);
        *s++ = conv_to_hex((i&0x0F00)>>8);
        *s++ = conv_to_hex((i&0x00F0)>>4);
        *s++ = conv_to_hex((i&0x000F));
        *s++ = ' ';

        for(int j=0; j<16 && i+j<nbytes;j++)
        {
            *s++ = conv_to_hex(buf[i+j]>>4);
            *s++ = conv_to_hex(buf[i+j] & 0x0F);
            *s++ = ' ';
        }
        *s++ = '\n';
    }
    *s = '\0';
    return str;
}
