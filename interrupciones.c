#include "MKL25Z4.h"

int main(void){
    // configuracion interrupcion
    while(1){

    }
}

ISR_BCD(){
    if(PORTA ->ISFR&(1<<4)){
        PORTA ->ISFR|(1<<4);
        //codigo interrupcion
    }
}