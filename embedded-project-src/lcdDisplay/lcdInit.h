#ifndef __LCDINIT_H__
#define __LCDINIT_H__

#include "tools/LcdDriver/Crystalfontz128x128_ST7735.h"
#include "tools/LcdDriver/HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.h"

Graphics_Context g_sContext;

void lcd_hw_init();

#endif
