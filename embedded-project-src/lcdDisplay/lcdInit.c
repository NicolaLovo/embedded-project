#include "lcdDisplay/lcdInit.h"

void lcd_hw_init() {
  /* Initializes display */
  Crystalfontz128x128_Init();

  /* Set default screen orientation */
  Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

  /* Initializes graphics context */
  Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128,
                       &g_sCrystalfontz128x128_funcs);
  Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_RED);
  Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
  GrContextFontSet(&g_sContext, &g_sFontFixed6x8);
  Graphics_clearDisplay(&g_sContext);
  Graphics_drawStringCentered(&g_sContext,
                              (int8_t *)"Embedded Project:", AUTO_STRING_LENGTH,
                              64, 20, OPAQUE_TEXT);
}
