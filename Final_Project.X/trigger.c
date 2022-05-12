
#include <xc.h>
#include "trigger.h"

void trigger(){
    TRIGGER_PIN = OUT;
    
    TRIGGER = ON;
    TRIGGER = OFF;
}