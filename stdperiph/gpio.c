


#include "gpio.h"
#include "stm32f767xx.h"

GPIO_TypeDef a;

void init_gpio(){

	GPIOB->MODER = GPIO_MODER_MODER0_0 | GPIO_MODER_MODER14_0 | GPIO_MODER_MODER7_1;
	GPIOB->OTYPER = 0x0;
	GPIOB->OSPEEDR = 0x0;
	GPIOB->PUPDR = 0x0;
	GPIOB->AFR[0] = GPIO_AFRL_AFRL7_1;

	GPIOC->MODER = 0x0;
	GPIOC->OTYPER = 0x0;
	GPIOC->OSPEEDR = 0x0;
	GPIOC->PUPDR = 0x0;

	GPIOD->MODER = GPIO_MODER_MODER14_1;
	GPIOD->OTYPER = 0x0;
	GPIOD->OSPEEDR = 0x0;
	GPIOD->PUPDR = 0x0;
	GPIOD->AFR[1] = GPIO_AFRL_AFRL6_1;

	GPIOE->MODER = GPIO_MODER_MODER9_1 | GPIO_MODER_MODER14_1;
	GPIOE->OTYPER = 0x0;
	GPIOE->OSPEEDR = 0x0;
	GPIOE->PUPDR = 0x0;
	GPIOE->AFR[1] = GPIO_AFRH_AFRH1_0 | GPIO_AFRH_AFRH6_0;

//	GPIOE->MODER = GPIO_MODER_MODER9_0 | GPIO_MODER_MODER14_0;
//	GPIOE->OTYPER = 0x0;
//	GPIOE->OSPEEDR = 0x0;
//	GPIOE->PUPDR = 0x0;
//	GPIOE->AFR[1] = 0x0;
}

void write_pin  (GPIO_TypeDef * port, unsigned int pin, unsigned int value){


	if(value == 1) port->BSRR |= 1 << pin;
	else 	  port->BSRR |= 1 << (16+pin) ;


}

void write_port (unsigned int port){


}                   

int  read_pin   (GPIO_TypeDef * port, unsigned int pin){
	unsigned int inp = port->IDR;
		inp = 0x01 & (inp >> pin);
            return inp;

}

int  read_pin_status   (GPIO_TypeDef * port, unsigned int pin){
	unsigned int inp = port->ODR;
		inp = 0x01 & (inp >> pin);
            return inp;
}

int  read_port  (unsigned int port){

	return 0;
}                   


void toggle_pin  (GPIO_TypeDef * port, unsigned int pin){
	if(read_pin_status(port, pin)  ) write_pin(port, pin, 0);
	else 	  write_pin(port, pin, 1) ;
}

int  dbnce_read_pin(GPIO_TypeDef * port, unsigned int pin) {
	if(read_pin(port, pin)){
		for(unsigned int dlay; dlay < 1000; dlay++);

		if(read_pin(port, pin)){
			while(read_pin(port, pin));
			return 1;
		}

		else return 0;

	}
	else return 0;

}