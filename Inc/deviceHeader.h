#include <stdint.h>

#ifndef DEVICEHEADER_H_
#define DEVICEHEADER_H_

#define F_CPU 8000000UL

typedef struct RCC_POINTERS
{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;
	uint32_t APB1ENR;
	uint32_t BDCR;
	uint32_t CSR;
}RCC_PERIPHERALS;

typedef struct GPIOA_POINTERS
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;
}GPIOA_PERIPHERALS;

typedef struct GPIOB_POINTERS
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;
}GPIOB_PERIPHERALS;

typedef struct AFIO_POINTERS
{
	uint32_t AFIO_EVCR;
	uint32_t AFIO_MAPR;
	uint32_t AFIO_EXTICR1;
	uint32_t AFIO_EXTICR2;
	uint32_t AFIO_EXTICR3;
	uint32_t AFIO_EXTICR4;
	uint32_t AFIO_MAPR2;
}AFIO_PERIPHERALS;

typedef struct USART1_POINTERS
{
	uint32_t SR;
	uint32_t DR;
	uint32_t BRR;
	uint32_t CR1;
	uint32_t CR2;
	uint32_t CR3;
	uint32_t GTPR;
}USART1_PERIPHERALS;

typedef struct EXTI_POINTERS
{
	uint32_t IMR;
	uint32_t EMR;
	uint32_t RTSR;
	uint32_t FTSR;
	uint32_t SWIER;
	uint32_t PR;
}EXTI_PERIPHERALS;

RCC_PERIPHERALS* RCC = (RCC_PERIPHERALS*)0x40021000;
GPIOA_PERIPHERALS* GPIOA = (GPIOA_PERIPHERALS*)0x40010800;
GPIOB_PERIPHERALS* GPIOB = (GPIOB_PERIPHERALS*)0x40010C00;
AFIO_PERIPHERALS* AFIO = (AFIO_PERIPHERALS*)0x40010000;
USART1_PERIPHERALS* USART1 = (USART1_PERIPHERALS*)0x40013800;
EXTI_PERIPHERALS* EXTI = (EXTI_PERIPHERALS*)0x40010400;
uint32_t* NVIC_ISER0 = (uint32_t*)0xE000E100;
uint32_t* NVIC_ICER0 = (uint32_t*)0xE000E180;


void delay(uint32_t del)
{
for( ; del; del--)
	 for(int i=0;i<3910;i++);
}



#endif  /* DEVICEHEADER_H_  */
