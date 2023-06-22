#if !defined(DELAY_H)
#define DELAY_H

#include <stm32f410rx.h>
#include <stm32f4xx.h>

void delay_ms(int delay)
{
    volatile int i; // try to stop optimisation removing loops
    for (; delay > 0; delay--)
    {
        for (i = 0; i < 3195; i++)
            ;
    }
}

#endif // DELAY_H
