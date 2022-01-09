#ifndef TWIGGLE_BIT_H_INCLUDED
#define TWIGGLE_BIT_H_INCLUDED

typedef enum
{
    CLEAR, SET, TOGGLE
}operation_t;

uint32_t twiggle_bit(uint32_t input, int bit, operation_t operation);

#endif // TWIGGLE_BIT_H_INCLUDED
