/* 
 * File:   trigger.h
 * Author: anth9
 *
 * Created on May 2, 2022, 11:34 PM
 */

#ifndef TRIGGER_H
#define	TRIGGER_H

#define TRIGGER PORTBbits.RB15
#define TRIGGER_PIN TRISBbits.TRISB15

#define OUT 0
#define IN 1

#define OFF 0
#define ON 1

void trigger();

#endif	/* TRIGGER_H */

