#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "Mult_CLLC_HAL.h"

extern int16_t vTimer0[4];         // Virtual Timers slaved off CPU Timers (A events)
extern int16_t vTimer1[4];         // Virtual Timers slaved off CPU Timers (B events)

extern void (*Alpha_State_Ptr)(void); // 基态状态机指针
extern void (*A_Task_Ptr)(void);      // State pointer A branch
extern void (*B_Task_Ptr)(void);      // State pointer B branch

#endif // STATE_MACHINE_H
