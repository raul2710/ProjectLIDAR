/* 
 * File:   lcd.h
 * Author: rault
 *
 * Created on 3 de Dezembro de 2023, 02:01
 */

#ifndef LCD_H
#define	LCD_H


/*
 * File:   lcd.c
 * Author: rault
 *
 * Created on 3 de Dezembro de 2023, 01:59
 */


#include <xc.h>
#include <pic18f4550.h>
#include <stdio.h>

#define _XTAL_FREQ 8000000
#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))
// Ajuste de tempo para o LCD
#define LCD_delay 5 // ~5mS
#define LCD_Startup 15 // ~15mS

// Comandos para o LCD Hitachi 44780U 
#define LCD_CLEAR 0x01
#define LCD_HOME 0x02
#define LCD_CURSOR_BACK 0x10
#define LCD_CURSOR_FWD 0x14
#define LCD_PAN_LEFT 0x18
#define LCD_PAN_RIGHT 0x1C
#define LCD_CURSOR_OFF 0x0C
#define LCD_CURSOR_ON 0x0E
#define LCD_CURSOR_BLINK 0x0F
#define LCD_CURSOR_LINE2 0xC0

// Comandos de acordo com o datasheet
#define FUNCTION_SET 0x28 // 4 bits de interface, 2 linhas, 5x8 de fonte
#define ENTRY_MODE 0x06 // Ajusta o "increment mode"
#define DISPLAY_SETUP 0x0C // Ajusta --> display on, cursor off, blink off

#define LCDLine1() LCDPutCmd(LCD_HOME) // 
#define LCDLine2() LCDPutCmd(LCD_CURSOR_LINE2) // 
#define shift_cursor() LCDPutCmd(LCD_CURSOR_FWD) // 
#define cursor_on() LCDPutCmd(LCD_CURSOR_ON) // 
#define DisplayClr() LCDPutCmd(LCD_CLEAR) // 

// Bits usados para os comandos
#define instr 0
#define data 1

// Pinos
#define LCD_PORT PORTD
#define LCD_PWR PORTDbits.RD7 // LCD power 
#define LCD_EN PORTDbits.RD6 // LCD enable
#define LCD_RW PORTDbits.RD5 // LCD read/write 
#define LCD_RS PORTDbits.RD4 // LCD register select line

#define NB_LINES 2 // Numero de linhas do LCD
#define NB_COL 16 // Numero de caracters por linha

void LCD_Initialize(void);
void LCDPutChar(char ch);
void LCDPutCmd(char ch);
void LCDPutStr(const char *); 
void LCDWriteNibble(char ch, char rs);
void LCDGoto(char pos, char ln);


#endif	/* LCD_H */

