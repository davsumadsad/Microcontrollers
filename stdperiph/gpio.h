#ifndef GPIO_H
#define GPIO_H


#include "stm32f767xx.h"

#define PIN_0  0
#define PIN_1  1
#define PIN_2  2
#define PIN_3  3
#define PIN_4  4
#define PIN_5  5
#define PIN_6  6
#define PIN_7  7
#define PIN_8  8
#define PIN_9  9
#define PIN_10 10
#define PIN_11 11
#define PIN_12 12
#define PIN_13 13
#define PIN_14 14
#define PIN_15 15





void init_gpio();

void write_pin  (GPIO_TypeDef * port, unsigned int pin, unsigned int value) ;
void write_port (unsigned int port)                   ;
int  read_pin   (GPIO_TypeDef * port, unsigned int pin) ;
int  read_pin_status   (GPIO_TypeDef * port, unsigned int pin) ;
int  read_port  (unsigned int port)                   ;
void toggle_pin  (GPIO_TypeDef * port, unsigned int pin);
int  dbnce_read_pin(GPIO_TypeDef * port, unsigned int pin) ;





#endif