#include <stdint.h>
#include "gpio.h"
#define UART ((NRF_UART_REG*)0X40002000)

typedef struct {
//TASKS
	volatile uint32_t STARTTRX; 
	volatile uint32_t STORPRX; 
	volatile uint32_t STARTTX; 
	volatile uint32_t STOPTX;
	volatile uint32_t BUFFER[3];
	volatile uint32_t SUSPEND;
	volatile uint32_t BUFFER0[56];
//EVENTS
	volatile uint32_t CTS;
	volatile uint32_t NCTS;
	volatile uint32_t RXDRDY;
	volatile uint32_t BUFFER[4];
	volatile uint32_t TXDRDY;
	volatile uint32_t BUFFER[1];
	volatile uint32_t ERROR;
	volatile uint32_t BUFFER1[7];
	volatile uint32_t RXTO;
	volatile uint32_t BUFFER2[110];
//REGISTERS
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile uint32_t BUFFER3[93];
	volatile uint32_t ERRORSRC;
	volatile uint32_t BUFFER4[31];
	volatile uint32_t ENABLE;
	volatile uint32_t BUFFER5;
	volatile uint32_t PSELRTS;
	volatile uint32_t PSELTXD;
	volatile uint32_t PSELCTS;
	volatile uint32_t PSELRXD; 
	volatile uint32_t RXD;
	volatile uint32_t TXD;
	volatile uint32_t BUFFER2;
	volatile uint32_t BAUDRATE; 
	volatile uint32_t CONFIG;
} NRF_UART_REG;

UART->BAUDRATE = 9600;  
UART->PSELCTS = 0xFFFFFFFF;
UART->PSELRXD = 0xFFFFFFFF;
UART->ENABLE = 4; 
UART->STARTRX = 1; 

void uart_init() {
}
void uart_send(char letter) {
	TXD = letter;
	while(!TXDRDY) {
		if(TXDRDY) {
			TXD = letter;
			TXDRDY = 0;  
		} 
	}
}
char uart_read()

