#include "interrupt.h"
#include "MKL25Z4.h"
#include <stdio.h>

bool numeros[10][7] = {
    {1,1,1,1,1,1,0}, //0
    {0,1,1,0,0,0,0}, //1
    {1,1,0,1,1,0,1}, //2
    {1,1,1,1,0,0,1}, //3
    {0,1,1,0,0,1,1}, //4
    {1,0,1,1,0,1,1}, //5
    {1,0,1,1,1,1,1}, //6
    {1,1,1,0,0,0,0}, //7
    {1,1,1,1,1,1,1}, //8
    {1,1,1,0,0,1,1}  //9
}

bool contBCD[10][4] = {
    {0,0,0,0}, //0
    {0,0,0,1}, //1
    {0,0,1,0}, //2
    {0,0,1,1}, //3
    {0,1,0,0}, //4
    {0,1,0,1}, //5
    {0,1,1,0}, //6 
    {0,1,1,1}, //7
    {0,0,0,0}, //8
    {1,0,0,1}, //9
}

bool contAnilloJohnson[8][8]{
    {1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0},
    {0,0,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,1},
}

void bcd(){
    for (int j = 0; j < 10; i++){
        for (int i = 0; i < 4; i++){
            PTA -> PSOR|=(contBCD[j][i] << i);
        }   
    }
}

void anillo(){
    for (int j = 0; j < 8; i++){
        for (int i = 0; i < 8; i++){
            PTA -> PSOR|=(contAnilloJohnson[j][i] << i);
        }   
    }
}

void johnson(){
    for (int j = 0; j < 8; i++){
        for (int i = 0; i < 8; i++){
            PTA -> PSOR|=(contAnilloJohnson[j][i] << i);
        }   
    }
    for (int j = 7; j <= 0; i--){
        for (int i = 7; i <= 0; i--){
            PTA -> PSOR|=(contAnilloJohnson[j][i] << i);
        }   
    }
}


void d7seg(){
    for (int j = 0; j < 10; i++){
        for (int i = 0; i < 7; i++){
            PTA -> PSOR|=(numeros[j][i] << i);
        }   
    }
}