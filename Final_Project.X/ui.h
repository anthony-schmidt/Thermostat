/* 
 * File:   ui.h
 * Author: anth9
 *
 * Created on May 4, 2022, 7:29 PM
 */

#ifndef UI_H
#define	UI_H

void ui_init_state();
void ui_init_interrupts(void);
void ui_init_pins(void);
void __attribute__((__interrupt__,no_auto_psv)) _CNInterrupt(void);
void __attribute__((__interrupt__,no_auto_psv)) _T1Interrupt(void);
void __attribute__((__interrupt__,no_auto_psv)) _T2Interrupt(void);
void __attribute__((__interrupt__,no_auto_psv)) _T3Interrupt(void);

#endif	/* UI_H */

