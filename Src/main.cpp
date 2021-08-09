#include<deviceHeader.h>

uint32_t del = 100;

uint8_t pinNumber = 4;

int main()
{
	RCC->APB2ENR |= (1<<2) | (1<<3) | (1<<0);
	GPIOA->CRL = 0X88888888;

	GPIOB->CRH  = 0X3 <<(4*4);

	AFIO -> AFIO_EXTICR1 &= 0x0000;

	EXTI -> IMR |= (1 << pinNumber);
	//EXTI -> RTSR &= 0x00000000;

	EXTI -> RTSR |= (1 << pinNumber);

	*NVIC_ISER0 |= (1 << (6+pinNumber));
  // remmember this will work upto gpio4 ,
	//because gpio 5 to 9 uses same interrupt handler . and has IRQ number  23

	while(1)
	 {
	  GPIOB->ODR^=0x1000;    // this is same as above commencted code / 0b1000 0000 0000
    delay(del);
	 }

}

void EXTI0_IRQHandler()
{   del-=10;
	delay(100);
	EXTI->PR = 1<<pinNumber;				// reset the pending bit by writing HIGH
}
void EXTI1_IRQHandler()
{
	del-=10;
	delay(100);
	EXTI->PR = 1<<pinNumber;				// reset the pending bit by writing HIGH
}
void EXTI2_IRQHandler()
{
	del-=10;
	delay(100);
	EXTI->PR = 1<<pinNumber;				// reset the pending bit by writing HIGH
}
void EXTI3_IRQHandler()
{
	del-=10;
	delay(100);
	EXTI->PR = 1<<pinNumber;				// reset the pending bit by writing HIGH
}
void EXTI4_IRQHandler()
{
	del-=10;
	delay(100);
	EXTI->PR = 1<<pinNumber;				// reset the pending bit by writing HIGH
}

