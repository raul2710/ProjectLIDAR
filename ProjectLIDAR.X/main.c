/* 
 * Servo control using POT with PIC
 * http://www.electronicwings.com
 */
#pragma config FOSC = INTOSCIO_EC
#pragma config FCMEN = OFF                                 
#pragma config BORV = 3
#pragma config WDT = OFF
#pragma config CPB = OFF
#pragma config CPD = OFF
//
#pragma config BOR=OFF, WDT=OFF, PWRT=ON
#pragma config CCP2MX=ON, PBADEN=OFF, MCLRE=ON
#pragma config DEBUG=OFF, STVREN=OFF,XINST=OFF, LVP=OFF, ICPRT=ON

#include <xc.h>
#include <pic18f4550.h>
#include "pwm.h"
#include "lcd.h"
#include "adc.h"

//----------------------------------------------------------------------

int main() 
{
    float Duty_Scale;
    int Period, valorADC;
    char convertido[10];
    OSCCON = 0x72;
    
    LCD_Initialize();

    ADC_Init();
    PWM_Init();                 /* Initialize PWM */
    Period = setPeriodTo(50);   /* 50Hz PWM frequency */
    /* Note that period step size will gradually increase with PWM frequency */
    
    while(1)
    {
        /* Scale Duty Cycle in between 3.0-12.0 */
        valorADC = ADC_Read(0);
        sprintf(convertido, "%i", valorADC);
        Duty_Scale = (((float)(valorADC/4.0)*9.0)/255.0) + 3.0;
        SetDutyCycleTo(Duty_Scale, Period);
        LCDPutStr(convertido);
        DisplayClr();
    }
}