/* 
 * File:   my_rbgLED.c
 * Author: aschmi25
 *
 * Created on March 28, 2022, 11:47 PM
 */

#include "my_rgbLED.h"

void rgbLED_init(){
    BLUE_LED_PIN = OUT;
    GREEN_LED_PIN = OUT;
    RED_LED_PIN = OUT;
}

void rgbLED_red() {
    BLUE_LED = OFF;
    GREEN_LED = OFF;
    RED_LED = ON;
}

void rgbLED_green() {
    BLUE_LED = OFF;
    GREEN_LED = ON;
    RED_LED = OFF;
}

void rgbLED_blue() {
    BLUE_LED = ON;
    GREEN_LED = OFF;
    RED_LED = OFF;
}

void rgbLED_yellow(){
    BLUE_LED = OFF;
    GREEN_LED = ON;
    RED_LED = ON;
}

void rgbLED_off(){
    BLUE_LED = OFF;
    GREEN_LED = OFF;
    RED_LED = OFF;
}

void rgbLED_killtime() {
    unsigned int i, j;
    for (j=0; j<6; j++) {
        for (i=0;i<30000;i++){}
    }
}

void rgbLED_set_brightness(int brightness){
    unsigned int i, j;
    for(j = 0; j < 20; j++){
        for(i = 0; i < 100; i++){
            if(i < brightness){
                rgbLED_blue();
            }
            else{
                rgbLED_off();
            }
        }
    }
}