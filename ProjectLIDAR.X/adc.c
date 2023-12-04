/*
 * File:   adc.c
 * Author: rault
 *
 * Created on 3 de Dezembro de 2023, 11:42
 */


#include "adc.h"

void ADC_Init()
{    
    TRISA = 0xff;		/*Port A como entrada*/
    ADCON1 = 0x0e;  		/*Ref vtg é VDD & configura com pino analógico*/    
    ADCON2 = 0x92;  		/* ajusta Fosc/32. */
    ADRESH=0;  			/*Faz um Flush no registrador de saida do ADC*/
    ADRESL=0;   
}

int ADC_Read(int channel)
{
    int digital;
    ADCON0 =(ADCON0 & 0b11000011)|((channel<<2) & 0b00111100);

    /*Seleciona canal 0 ou seja(CHS3CHS2CHS1CHS0=0000)& ADC é off*/
    ADCON0 |= ((1<<ADON)|(1<<GO));/*Enable ADC para iniciar conversão*/

    /* espera o final da conversão */
    while(ADCON0bits.GO_nDONE==1);

    digital = (ADRESH*256) | (ADRESL);/*Combina 8-bit LSB e 2-bit MSB*/
    return(digital);
}
