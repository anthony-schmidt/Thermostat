/* 
 * File:   my_rbgLED.h
 * Author: aschmi25
 *
 * Created on March 28, 2022, 11:46 PM
 */
#ifndef MY_RBGLED_H
#define	MY_RBGLED_H

#include <xc.h> // include processor files - each processor file is guarded.  

//Create pins and set outputs
#define BLUE_LED_PIN TRISAbits.TRISA0     // BLUE LED on POrt A0
#define BLUE_LED LATAbits.LATA0
#define GREEN_LED_PIN TRISAbits.TRISA1  // GREEN LED on Port A1
#define GREEN_LED LATAbits.LATA1
#define RED_LED_PIN TRISBbits.TRISB1    // RED LED on Port B1
#define RED_LED LATBbits.LATB1

// LED States
#define OFF 0
#define ON 1

// Pin States
#define OUT 0
#define IN  1

//Function Prototypes
void rgbLED_init();
void rgbLED_red();
void rgbLED_green();
void rgbLED_blue();
void rgbLED_yellow();
void rgbLED_off();
void rgbLED_killtime();
int rgbLED_get_state();
void rgbLED_set_brightness(int brightness);

#endif

