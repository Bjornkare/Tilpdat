#include "gpio.h"
#include "uart.h"
#include <stdint.h>

int main(){
  uart_init();

	// Configure buttons
	GPIO->PIN_CNF[17] = 0; // A-knapp
	GPIO->PIN_CNF[26] = 0; // B-knapp

	int sleep = 0;
	while(1){
		if(!(GPIO->IN & (1 << 17))){ //Sjekk om knapp A er trykt
		    uart_send('A');
		}

		if(!(GPIO->IN & (1 << 26))){ //Sjekk om knapp B er trykt
			uart_send('B');
 		}

		sleep = 10000;
		while(--sleep);
	}
	return 0;
}
