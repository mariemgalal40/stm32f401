#include "EXIT.h"

void Timer_EnableClock(unsigned char bit_no) {

      *RCC_APB2ENR |= (0x01 << bit_no);
}
