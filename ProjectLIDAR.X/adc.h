/* 
 * File:   adc.h
 * Author: rault
 *
 * Created on 3 de Dezembro de 2023, 11:41
 */

#ifndef ADC_H
#define	ADC_H

#include <xc.h>
#include <pic18f4550.h>
#include <stdio.h>

#define vref 5.00		/*  5V de voltagem de referencia do conversor*/

void ADC_Init();
int ADC_Read(int channel);

#endif	/* ADC_H */

