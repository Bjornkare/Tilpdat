#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"


int main(){

    for (int i = 4; i < 13; i++){
        GPIO->DIRSET = (1 << i);
        GPIO ->OUTCLR = (1 << i);
    }
    gpiote_init();
    ppi_init();

    while(1){
    }




    return 0;
}