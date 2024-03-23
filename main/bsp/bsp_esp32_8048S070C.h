
#ifndef _BSP_ESP32_8048S070C_H
#define _BSP_ESP32_8048S070C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

// The pixel number in horizontal and vertical
#define LCD_H_RES (800)
#define LCD_V_RES (480)

lv_disp_t *bsp_lvgl_get_disp(void);
void bsp_8048S070C_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
