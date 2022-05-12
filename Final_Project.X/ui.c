#include <stdio.h>
#include <xc.h>
#include <math.h>
#include "uart.h"
#include "ui.h"
#include "my_buttons.h"
#include "my_rgbLED.h"
#include "lcd.h"
#include "ds1631.h"

int brightness = 100;
int on_duty = 0;
int counter = 0;
int old_brightness = 0;

int confirmed_up = 0;
int confirmed_down = 0;
int confirmed_both = 0;
int up_debounced = 0;
int down_debounced = 0;
int both_debounced = 0;

const int TEMP_MAX_x1 = 80;
const int TEMP_MIN_x1 = 60;

int led_color = 0;
enum Led_color_en {LED_COLOR_GREEN_en, 
LED_COLOR_RED_en, 
LED_COLOR_BLUE_en};

int old_state = -1; 
int old_temp_x10 = 0;
int old_cooling_on = -1;
int old_heat_on = -1;

struct State{
    int state_id;
    int temp_x10;
    int temp_high_x1;
    int temp_low_x1;
    int cooling_on;
    int heat_on;
};
struct State state;
            
void ui_init_state(){
    state.state_id = 0;
    state.temp_x10 = -100;
    state.temp_high_x1 = 75;
    state.temp_low_x1 = 70;
    state.cooling_on = 0;
    state.heat_on = 0;
    old_temp_x10 = state.temp_x10;
}

void ui_init_interrupts(void) {
    INTCON2bits.GIE = 1;        /* turn on all interrupts */
    INTCON2bits.INT0EP = 1;
    INTCON2bits.INT1EP = 1;
    INTCON2bits.INT2EP = 1;
    
    //Change Config
    IFS1bits.CNIF = 0;      /* Clear NC interrupt flag*/
    IPC4bits.CNIP = 2;      /*Set CN interrupt to high priority */

    //Timer1 Config
    T1CONbits.TCS = 0;          /* use internal clock */
    T1CONbits.TGATE = 0;
    TMR1 = 0;
    
    T1CONbits.TCKPS = 0;        /* 1:1 scaling */
    PR1 = 5000;
    
    IFS0bits.T1IF = 0;          /* Clear timer interrupt flag*/
    IPC0bits.T1IP = 2;          /* Set timer priority */
    IEC0bits.T1IE = 1;          /* enable timer interrupts */
    
    //Timer2 Config
    T2CONbits.TCS = 0;          /* use internal clock */
    T2CONbits.TGATE = 0;
    TMR2 = 0;
    
    T2CONbits.TCKPS = 0;        /* 1:1 scaling */
    PR2 = 5000;
    
    IFS0bits.T2IF = 0;          /* Clear timer interrupt flag*/
    IPC1bits.T2IP = 5;          /* Set timer priority */
    IEC0bits.T2IE = 1;          /* enable timer interrupts */
    
    //Timer3 Config
    T3CONbits.TCS = 0;          /* use internal clock */
    T3CONbits.TGATE = 0;
    TMR3 = 0;
    
    T3CONbits.TCKPS = 2;        /* 1:64 scaling */
    PR3 = 5000;
    
    IFS0bits.T3IF = 0;          /* Clear timer interrupt flag*/
    IPC2bits.T3IP = 5;          /* Set timer priority */
    IEC0bits.T3IE = 1;          /* enable timer interrupts */
    
    
    //Turn on timers
    T1CONbits.TON = 0;          /* turn off T1 */
    T2CONbits.TON = 1;          /* turn on T2 */
    T3CONbits.TON = 1;          /* turn on T3 */
    IEC1bits.CNIE = 1;      /*Enable CN Interrupts*/
}

void ui_init_pins(void){
    //Button 1
    TRISAbits.TRISA2 = 1; /*Set pin as input */
    CNENAbits.CNIEA2 = 1; /*Enable CN*/
    CNPUAbits.CNPUA2 = 1; /*Enable Pull-up*/
    
    //Button 2
    TRISBbits.TRISB4 = 1; /*Set pin as input */
    CNENBbits.CNIEB4 = 1; /*Enable CN*/
    CNPUBbits.CNPUB4 = 1; /*Enable Pull-up*/
}


void __attribute__((__interrupt__,no_auto_psv)) _CNInterrupt(void) {
    IEC1bits.CNIE = 0;      /*Disable CN Interrupts*/
    IFS1bits.CNIF = 0;      /*Clear interrupt flag*/
    counter = 0;
    T1CONbits.TON = 1; /* turn on T1 */
    
    confirmed_up = 0;
    confirmed_down = 0;
    confirmed_both = 0;
    up_debounced = 0;
    down_debounced = 0;
    both_debounced = 0;
}

void __attribute__((__interrupt__,no_auto_psv)) _T1Interrupt(void) {
    T1CONbits.TON=  0; /* turn off T1 */
    TMR1 = 0;
    IFS0bits.T1IF = 0; /* Clear timer interrupt flag */
    IFS1bits.CNIF = 0;
    counter++;
    int button_up = button_1_get_value();
    int button_down = button_2_get_value();
    
    if(counter >= 10){
        counter = 0;

        if(button_up && !button_down){
            if(confirmed_up < 10){
                confirmed_up++;
            }
            confirmed_down = 0;
            confirmed_both = 0;
        }
        else if(button_down && !button_up){
            if(confirmed_down < 10){
                confirmed_down++;
            }
            confirmed_up = 0;
            confirmed_both = 0;
        }
        else if(button_down && button_up){
            if(confirmed_both < 10){
                confirmed_both++;
            }
            confirmed_up = 0;
            confirmed_down = 0;
        }
        else{
            confirmed_up = 0;
            confirmed_down = 0;
            confirmed_both = 0;
        }
        
        if(confirmed_up == 3){up_debounced = 1;}
        else{up_debounced = 0;}
        
        if(confirmed_down == 3){down_debounced = 1;}
        else{down_debounced = 0;}
        
        if(confirmed_both == 3){both_debounced = 1;}
        else{both_debounced = 0;}
        
        
        if(down_debounced){
            switch(state.state_id){
                case 0:
                    break;
                case 1:
                    if(state.temp_low_x1 == TEMP_MIN_x1){break;}
                    state.temp_low_x1--;
                    break;
                case 2:
                    if(state.temp_high_x1 == (state.temp_low_x1 + 1)){break;}
                    state.temp_high_x1--;
            }   
        }
        
        if(up_debounced){
            switch(state.state_id){
                case 0:
                    break;
                case 1:
                    if(state.temp_low_x1 == (state.temp_high_x1 - 1)){break;}
                    state.temp_low_x1++;
                    break;
                case 2:
                    if(state.temp_high_x1 == TEMP_MAX_x1){break;}
                    state.temp_high_x1++;
            }
        }
        
        if(both_debounced){
            if(state.state_id >= 2){
                state.state_id = 0;
            }
            else{
                state.state_id++;
            }
        }
    }
  
    if(!button_down && !button_up){
        T1CONbits.TON = 0; /* turn off T1 */
        IFS1bits.CNIF = 0;
        IEC1bits.CNIE = 1;
    }
    else{
        IEC1bits.CNIE = 0;
        T1CONbits.TON = 1; /* turn on T1 */
    }
    
} 

void __attribute__((__interrupt__,no_auto_psv)) _T2Interrupt(void) {
    T2CONbits.TON = 0;      /* turn off T2 */
    IFS0bits.T2IF = 0; /* Clear timer interrupt flag */
    TMR2 = 0;
    int time = 0;
    
    if(state.cooling_on){
        led_color = LED_COLOR_BLUE_en;
    } 
    else if(state.heat_on){
        led_color = LED_COLOR_RED_en;
    }
    else{
        led_color = LED_COLOR_GREEN_en;
    }
    
    if((brightness == 0) || ((on_duty == 0) && (brightness != 100))){
        rgbLED_off();
        time = 50 * (100 - brightness);
        PR2 = time;
        on_duty = 1;
        T2CONbits.TON = 1;      /* turn on T2 */
    }
    else{
        //rgbLED_blue();
        switch(led_color){
            case LED_COLOR_GREEN_en:
                rgbLED_green();
                break;
            case LED_COLOR_RED_en:
                rgbLED_red();
                break;
            default:
                rgbLED_blue();
        }
        time = 50 * brightness;
        PR2 = time;
        on_duty = 0;
        T2CONbits.TON = 1;      /* turn on T2 */
    }
}

void __attribute__((__interrupt__,no_auto_psv)) _T3Interrupt(void) {
    T3CONbits.TON = 0;      /* turn off T3 */
    IFS0bits.T3IF = 0; /* Clear timer interrupt flag */
    TMR3 = 0;
    LCD_clr();
    state.temp_x10 = ds1631_read_temp() * 10 + .5f;
    if(state.temp_x10 > ((state.temp_high_x1 * 10) + ((state.cooling_on) ? (-5) : (+5)) )){
        state.cooling_on = 1;
        state.heat_on = 0;
    } 
    else if(state.temp_x10 < ((state.temp_low_x1 * 10) + ((state.heat_on) ? (+5) : (-5)) )){
        state.cooling_on = 0;
        state.heat_on = 1;
    }
    else{
        state.cooling_on = 0;
        state.heat_on = 0;
    }
    
    LCD_print_big_temp(state.temp_x10);
    LCD_print_12_blanks();
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    
    if(state.cooling_on){
        LCD_array_print(snowflake_T);
    }
    else if(state.heat_on){
        LCD_array_print(flame_T);
    }
    else{
        LCD_Character(' ');
        LCD_Character(' ');
    }
    
    LCD_Character('[');
    
    int a = state.temp_low_x1;
    a /= 10;
    
    if((state.state_id == 1) && (LCD_flicker())){
        LCD_Character(' ');
        LCD_Character(' ');
    }
    else{
        LCD_Character(a + 48);
        LCD_Character((state.temp_low_x1 - 10 * a) + 48);
    }
    
    LCD_Character(',');
    
    a = state.temp_high_x1;
    a /= 10;
    
     if((state.state_id == 2) && (LCD_flicker())){
        LCD_Character(' ');
        LCD_Character(' ');
    }
    else{
        LCD_Character(a + 48);
        LCD_Character((state.temp_high_x1 - 10 * a) + 48);
    }
    
    LCD_Character(']');
    
    LCD_Character(' ');
    LCD_Character(' ');
    LCD_Character(' ');
    
    if(state.cooling_on){
        LCD_array_print(snowflake_B);
        if(old_cooling_on != state.cooling_on){
            old_cooling_on = state.cooling_on;
            printf("    Air Conditioning is now on\n\r");
        }
    }
    else if(state.heat_on){
        LCD_array_print(flame_B);
        if(old_heat_on != state.heat_on){
            old_heat_on = state.heat_on;
            printf("    Furnace is now on\n\r");
        }
    }
    else{
        LCD_Character(' ');
        LCD_Character(' ');
        if((old_state == 0) && (old_state != state.state_id)){
            printf("    System is now off\n\r");
        }
    }
    
    if((old_state == 1) && (state.state_id == 2)){
        printf("    Low Temperature Setting = %d; High Temperature Setting = %d\n\r", state.temp_low_x1, state.temp_high_x1);
    }
    else if((old_state == 2) && (state.state_id == 0)){
        printf("    Low Temperature Setting = %d; High Temperature Setting = %d\n\r", state.temp_low_x1, state.temp_high_x1);
    }
    
    if((old_state == -1) || (old_state != state.state_id)){
        switch(state.state_id){
            case 0:           
                printf("    System is now in Running Mode\n\r");
                break;
            case 1:
                printf("    System is Programming LOW Temperature\n\r");
                break;
            case 2:
                printf("    System is Programming HIGH Temperature\n\r");
                break;
        }
    }
    
    float float_temp = ((float) state.temp_x10)/10;
    if(old_state == -1){
        printf("    Low Temperature Setting = %d; High Temperature Setting = %d\n\r", state.temp_low_x1, state.temp_high_x1);
        old_temp_x10 = state.temp_x10;
    }
    else{
        if((state.temp_x10 - old_temp_x10) >= 5){
            printf("    Temperature increased %.1f degrees to %.1f\r\n", ((float) (state.temp_x10 - old_temp_x10)/10), float_temp);
            old_temp_x10 = state.temp_x10;
        }
        else if((old_temp_x10 - state.temp_x10) >= 5){
            printf("    Temperature decreased %.1f degrees to %.1f\r\n", ((float) (old_temp_x10 - state.temp_x10)/10), float_temp);
            old_temp_x10 = state.temp_x10;
        }
    }
    
    old_state = state.state_id;
    
    T3CONbits.TON = 1;      /* turn on T3 */
}
