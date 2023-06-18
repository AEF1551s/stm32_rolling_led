#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//User defined includes
#include <Device/stm32f410rx.h>

void clock_init(){

}

void pin_init(){

}



int main(void)
{
    /* Loop forever */
	for(;;);
}
