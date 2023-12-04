/*
 * File:   lcd.c
 * Author: rault
 *
 * Created on 3 de Dezembro de 2023, 02:06
 */

#include "lcd.h"

void LCD_Initialize()
{
    // limpa os bits TRIS bits
    LCD_PORT = 0;

    TRISD = 0x00;

    // liga o LCD
    LCD_PWR = 1;

    // Espera estabilizar o LCD
    __delay_ms(LCD_Startup);

    // comando de inicialização
    LCDPutCmd(0x32);

    // ajusta o LCD
    LCDPutCmd(FUNCTION_SET);

    // liga o display
    LCDPutCmd(DISPLAY_SETUP);

    DisplayClr();

    // Ajusta o cursor
    LCDPutCmd(ENTRY_MODE);

}


void LCDWriteNibble(char ch, char rs)
{
    // sempre manda o bit mais alto
    ch = (ch >> 4);

    // mascara para o nibble
    ch = (ch & 0x0F);

    // limpa a parte de baixo do LCD_PORT
    LCD_PORT = (LCD_PORT & 0xF0);

    // move dados para o LCD_PORT
    LCD_PORT = (LCD_PORT | ch);

    // Ajusta dados/instr bit sendo 0 = instruções; 1 = dados
    LCD_RS = rs;

    // RW - entra no modo escrita de comando
    LCD_RW = 0;

    // habilita o LCD
    LCD_EN = 1;

    // desliga depois do comando
    LCD_EN = 0;
}

void LCDPutChar(char ch)
{
    __delay_ms(LCD_delay);

    //manda o nibble superior primeiro 
    LCDWriteNibble(ch,data);

    //pega o nibble baixo
    ch = (ch << 4);

    // envia o nibble baixo
    LCDWriteNibble(ch,data);
}


void LCDPutCmd(char ch)
{
    __delay_ms(LCD_delay);

    //manda o nibble superior primeiro 
    LCDWriteNibble(ch,instr);

    //pega o nibble baixo
    ch = (ch << 4);

    __delay_ms(1);

    //envia o nibble baixo
    LCDWriteNibble(ch,instr);
}


void LCDPutStr(const char *str)
{
    char i=0;

    // Enquanto a string não termina envia
    while (str[i])
    {
        // caracter atual
        LCDPutChar(str[i++]);
    }
}

void LCDGoto(char pos,char ln)
{
    // testa se a linha ou coluna estão certos
    if ((ln > (NB_LINES-1)) || (pos > (NB_COL-1)))return;

    // comando LCD_Goto 
    LCDPutCmd((ln == 1) ? (0xC0 | pos) : (0x80 | pos));

    // Espera o LCD terminar
    __delay_ms(LCD_delay);
}
/**
 * Fim do arquivo
*/

