#ifndef _BSP_ESP32_H
#define _BSP_ESP32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "bsp_esp32_config.h"

#ifdef TARGET_BOARD_ESP32_8048S070c
#define TARGET_HAVE_LVGL
#include "bsp_esp32_8048S070C.h"

#endif

void bsp_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
