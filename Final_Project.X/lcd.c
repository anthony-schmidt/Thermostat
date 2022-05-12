/* 
 * File:   lcd.c
 * Author: aschmi25
 *
 * Created on May 3, 2022, 7:38 PM
 */

#include <xc.h>
#include "lcd.h"

void LCD_init(){
    LCD_SCE_PIN = OUT;
    LCD_RESET_PIN = OUT;
    LCD_DC_PIN = OUT;

    SPI1CON1bits.MSTEN = 1;    // make master
    SPI1CON1bits.PPRE = 0b11;  // 1:1 primary prescale
    SPI1CON1bits.SPRE = 0b111; // 1:1 secondary prescale
    SPI1CON1bits.MODE16 = 0;   // 8-bit transfer mode
    SPI1CON1bits.SMP = 0;      // sample in middle
    SPI1CON1bits.CKE = 1;      // Output on falling edge
    SPI1CON1bits.CKP = 0;      // CLK idle state low
    SPI1STATbits.SPIEN = 1;    // enable SPI1
    
    LCD_RESET = LOW;
    LCD_RESET = HIGH;
        
    LCD_Write(LCD_COMMAND, 0x21);  // LCD Extended Commands.
    LCD_Write(LCD_COMMAND, 0x20 );  // Set LCD Vop (Contrast). 
    LCD_Write(LCD_COMMAND, 0x04 );  // Set Temp coefficent. //0x04
    LCD_Write(LCD_COMMAND, 0x13 );  // LCD bias mode 1:48. //0x13
    LCD_Write(LCD_COMMAND, 0x20 );  // LCD Basic Commands
    LCD_Write(LCD_COMMAND, 0x0C );  // LCD in normal mode.
   
    LCD_clr();
}


void LCD_Write(LCDBYTE dc, LCDBYTE data) {
    LCD_SCE = LOW;    // Selection LCD panel
    LCD_DC = dc;      // Indicate Data/Command signal
    SPI1BUF = data;   // Put data in output buffer for SPI1
    while(!SPI1STATbits.SPIRBF){} // wait for it to send
    Nop();            // A little extra wait time
    LCD_SCE = HIGH;   // Deselect LCD panel
       
}

void LCD_Character(char character)
{
    int index;
    LCD_Write(LCD_DATA, 0x00);
    for (index = 0; index < 5; index++) {
        LCD_Write(LCD_DATA, ASCII[character - 0x20][index]);
    }
    LCD_Write(LCD_DATA, 0x00);
}

void LCD_clr(void){
    int i;
    for (i=0;i<6*84;i++){
        LCD_Write(LCD_DATA,0x00);
    }
    LCD_Write(LCD_COMMAND,0x40);
}

void LCD_print_temp(int temp_x10){
    LCD_Character('T');
    LCD_Character('e');
    LCD_Character('m');
    LCD_Character('p');
    LCD_Character(':');
    LCD_Character(' ');
    
    int temp_i = temp_x10;
    int a;
    a = temp_i/100;
    LCD_Character(a + 48);
    temp_i = temp_i - a*100;
    a = temp_i/10;
    LCD_Character(a + 48);
    LCD_Character('.');
    a = temp_i - a*10;
    LCD_Character(a + 48);
    LCD_Character(' ');
    LCD_Character(' ');
}

void LCD_print_12_blanks(){
    int i;
    for(i = 0; i < 12; i++){
        LCD_Character(' ');
    }
}

void LCD_print_string(char *string){
    int i = 0;
    char c;
    int rest_zeros = 0;
    for(i = 0; i < 12; i++){
        c = string[i];
        if(c == 0){rest_zeros = 1;}
        if(rest_zeros){LCD_Character(' ');}
        else{LCD_Character(c);}
    }
}

void LCD_print_large_temp(int a1, int a2, int a3){
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_big_character(0, a1 + 48);
    LCD_big_character(0, a2 + 48);
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_big_character(1, a1 + 48);
    LCD_big_character(1, a2 + 48);
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_big_character(2, a1 + 48);
    LCD_big_character(2, a2 + 48);
    LCD_Character('.');
    LCD_Character(a3 + 48);
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
}

LCDBYTE LCD_print_large_temp_aux(int line_num, LCDBYTE byte){
    unsigned long a = 0;
    if(byte & 128){a += (7ul << 21);}
    if(byte & 64){a += (7ul << 18);}
    if(byte & 32){a += (7ul << 15);}
    if(byte & 16){a += (7ul << 12);}
    if(byte & 8){a += (7ul << 9);}
    if(byte & 4){a += (7ul << 6);}
    if(byte & 2){a += (7ul << 3);}
    if(byte & 1){a += (7ul << 0);}
    a <<= 2;
    
    if(line_num == 0){return (unsigned char) a;}
    else if(line_num == 1){return (unsigned char) (a >> 8);}
    else{return (unsigned char) (a >> 16);}
}

void LCD_big_character(int line_num, LCDBYTE character){
    LCDBYTE aux, byte;
    LCD_Write(LCD_DATA, 0x00);
   /* for (index = 0; index < 6; index++) {
        byte = ASCII[character - 0x20][index]; // LCD_Write(LCD_DATA, ASCII[character - 0x20][index]);
        aux = LCD_print_large_temp_aux(line_num, byte);
        LCD_Write(LCD_DATA, aux);
        LCD_Write(LCD_DATA, aux);
    }*/
    LCD_Write(LCD_DATA, 0x00);
    
    byte = ASCII[character - 0x20][0]; // LCD_Write(LCD_DATA, ASCII[character - 0x20][index]);
    aux = LCD_print_large_temp_aux(line_num, byte);
    LCD_Write(LCD_DATA, aux);
    LCD_Write(LCD_DATA, aux);
    
    byte = ASCII[character - 0x20][1]; // LCD_Write(LCD_DATA, ASCII[character - 0x20][index]);
    aux = LCD_print_large_temp_aux(line_num, byte);
    LCD_Write(LCD_DATA, aux);
    LCD_Write(LCD_DATA, aux);
    
    byte = ASCII[character - 0x20][2]; // LCD_Write(LCD_DATA, ASCII[character - 0x20][index]);
    aux = LCD_print_large_temp_aux(line_num, byte);
    LCD_Write(LCD_DATA, aux);
    LCD_Write(LCD_DATA, aux);
    
    byte = ASCII[character - 0x20][3]; // LCD_Write(LCD_DATA, ASCII[character - 0x20][index]);
    aux = LCD_print_large_temp_aux(line_num, byte);
    LCD_Write(LCD_DATA, aux);
    LCD_Write(LCD_DATA, aux);
    
    byte = ASCII[character - 0x20][4]; // LCD_Write(LCD_DATA, ASCII[character - 0x20][index]);
    aux = LCD_print_large_temp_aux(line_num, byte);
    LCD_Write(LCD_DATA, aux);
    LCD_Write(LCD_DATA, aux);
    
    LCD_Write(LCD_DATA, 0x00);
    LCD_Write(LCD_DATA, 0x00);
}

void LCD_print_big_temp(int temp_x10){
    int temp_i = temp_x10;
    int a1, a2, a3;
    a1 = temp_i/100;
    temp_i = temp_i - a1*100;
    a2 = temp_i/10;
    a3 = temp_i - a2*10;
    LCD_print_large_temp(a1, a2, a3);
}

int LCD_flicker(){
    static int counter = 0; 
    const int HALF_PERIOD = 1;
    counter++;
    if(counter > 2*HALF_PERIOD){counter = 0;
    }
    if(counter > HALF_PERIOD){return 1;
    }
    return 0;
}

void LCD_array_print(const LCDBYTE *array)
{
    int index;
    LCD_Write(LCD_DATA, 0x00);
    LCD_Write(LCD_DATA, 0x00);
    for (index = 0; index < 10; index++) {
        LCD_Write(LCD_DATA, array[index]);
    }
    LCD_Write(LCD_DATA, 0x00);
    LCD_Write(LCD_DATA, 0x00);
}
