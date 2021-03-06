/***********************************************************************/
/*                                                                     */
/*  FILE        :Empty.c                                               */
/*  DATE        :Mon, Jan 08, 2007                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :Other                                                 */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.0).     */
/*                                                                     */
/***********************************************************************/
     
#include "qsk_bsp.h"
#include "qsk_switch.h"
#include "qsk_led.h"
#include "qsk_lcd.h"
#include <stdio.h>
#include <string.h>



// prototypes

void mcu_init(void);	              

/* *******************************************************************
 Description:
 Entry:
 Returns:
 
 Notes:
 
***********************************************************************/ 

#pragma INTERRUPT Switch1Handler
#pragma INTERRUPT Switch2Handler

void InitSwitchInt(void) {
	_asm("fset i");
	
	// S102
	ilvl0_int0ic = 0;
	ilvl1_int0ic = 1;
	ilvl2_int0ic = 0;
	pol_int0ic = 0;
	
	// S101
	ilvl0_int1ic = 1;
	ilvl1_int1ic = 1;
	ilvl2_int1ic = 1;
	pol_int1ic = 0;
} 

void Switch1Handler(void) {
	_asm("fset i");
	pd8_0 = 1;
	p8_0 = !p8_0;
}

void Switch2Handler(void) {
	int i = 0;
	char buf[3] = {0,};
	
	_asm("fset i");
	
	for (i = 1 ; i <= 10 ; i++) {
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%02d", i);
		DisplayString(LCD_LINE1, buf);
		Delay(600);
	}
}

void main(void)
{
	
	int a = 0, b = 0, c = 0;
	
	mcu_init();
	InitDisplay();
	InitSwitch();
	InitSwitchInt();
	
	// S103
	pd7_2 = 1;
	p7_2 = 1;
	while(1) {
		if( !p8_1 || c == 1 ) {
			c = 1;
			if( p8_1 ) {
				p7_2 = !p7_2;
				c = 0;
			}
		}
	}
	
}

