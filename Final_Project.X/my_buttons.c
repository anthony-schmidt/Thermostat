/* 
 * File:   my_buttons.c
 * Author: aschmi25
 *
 * Created on March 28, 2022, 11:47 PM
 */

#include <xc.h>
#include "my_buttons.h"

void button_1_init(){
    TRISAbits.TRISA2 = 1;
}
void button_2_init(){
    TRISBbits.TRISB4 = 1;
}

int button_1_get_value(){
    if(PORTAbits.RA2 == 0){ return 1;}
    else{ return 0;}
}

int button_2_get_value(){
    if(PORTBbits.RB4 == 0){ return 1;}
    else { return 0;}
}

int button_get_values(){
     if(PORTAbits.RA2 == 0 || PORTBbits.RB4 == 0){ return 1;}
     {return 0;}
}

void button_killtime(){
    unsigned int i, j;
    for (j=0; j<4; j++) {
        for (i=0;i<800;i++){}
    }
}

int button_get_action(){
    
    int button_1_val = button_1_get_value();
    int button_2_val = button_2_get_value();
    
    //If Neither button is pressed
    if((button_1_val == 1) && (button_2_val == 1)){return 0;}
    
    //If both are pressed return 3
    if((button_1_val == 0) && (button_2_val == 0)){return 3;}
    
    //If button 1 is pressed, return 1
    if(button_1_val == 0){ return 1;}
    
    //If button 2 is pressed, increase brightness
    if(button_2_val == 0){ return 2;}
    
    //Else return 0
    return 0;
}
