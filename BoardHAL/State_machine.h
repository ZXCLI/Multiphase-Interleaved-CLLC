#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "CLLC_HAL.h"
#include "CLLC.h"
#include "MY_DEBUG.h"

extern int16_t vTimer[4];         // Virtual Timers slaved off CPU Timers (A events)
extern int16_t vTimerCompare[4];        // Virtual Timers slaved off CPU Timers (B events)

extern void (*Alpha_State_Ptr)(void); // 基态状态机指针
extern void (*A_Task_Ptr)(void);      // State pointer A branch
extern void (*B_Task_Ptr)(void);      // State pointer B branch

void A0(void); // A branch
void B0(void); // B branch

void A1(void); 
void A2(void); 

void B1(void); 
void B2(void); 
void B3(void);



#endif // STATE_MACHINE_H
