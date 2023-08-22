
#ifndef PWM_H
#define PWM_H

#define SPI1
#define SPI1_BUFF
#define SPI2
#define SPI2_BUFF


#define spi_reg_num 8


extern int spi_reg[spi_reg_num];

void init_pwm();
void write_spi();
int read_spi();




#endif
