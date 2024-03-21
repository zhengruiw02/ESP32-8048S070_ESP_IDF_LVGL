
#ifndef _BSP_ESP32_8048S070C_H
#define _BSP_ESP32_8048S070C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

lv_disp_t *bsp_lvgl_get_disp(void);
void bsp_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
