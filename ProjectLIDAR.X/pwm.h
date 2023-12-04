/* 
 * File:   pwm.h
 * Author: rault
 *
 * Created on 3 de Dezembro de 2023, 02:21
 */

#ifndef PWM_H
#define	PWM_H

#include <xc.h>
#include <pic18f4550.h>
#include <stdio.h>
#include <math.h>

#define MINTHR              8000
#define RESOLUTION          488

#define InternalOsc_8MHz    8000000
#define InternalOsc_4MHz    4000000
#define InternalOsc_2MHz    2000000
#define InternalOsc_1MHz    1000000
#define InternalOsc_500KHz  500000
#define InternalOsc_250KHz  250000
#define InternalOsc_125KHz  125000
#define InternalOsc_31KHz   31000

#define Timer2Prescale_1    1
#define Timer2Prescale_4    4
#define Timer2Prescale_16   16


void PWM_Init();
int setPeriodTo(unsigned long FPWM);/* Set period */
void SetDutyCycleTo(float Duty_cycle, int Period);/* Set Duty cycle for given period */


#endif	/* PWM_H */

