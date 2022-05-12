/* 
 * File:   main.c
 * Author: aschmi25
 *
 * Created on April 28, 2022, 2:59 PM
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "uart.h"
#include "i2c.h"
#include "ds1631.h"
#include "lcd.h"
#include "my_rgbLED.h"
#include "my_buttons.h"
#include "ui.h"

int main(void) {
   
    //Serial logging
    uart_config();
    printf("\033[2J\033[;H");
    printf("BEGINNING OF LOG\r\n\n");
    printf("Initializing System\r\n");
    
    //LCD screen setup
    printf("    Configuring Hardware\r\n");
    ui_init_state();
    ui_init_pins();
    LCD_init();
    LCD_clr();
    LCD_print_string("Initializing");
    
    //Configure system
    i2c_config();
    ds1631_config();
    rgbLED_init();
    button_1_init();
    button_2_init();
    
    printf("    Start Measuring Temperature\r\n");
    ds1631_start_convert();

    printf("    Start the UI\r\n\n");
    ui_init_interrupts();
    
    printf("System Up and Running\r\n");
    
    while(1) {
        Idle();
    }   
    return 0;
}