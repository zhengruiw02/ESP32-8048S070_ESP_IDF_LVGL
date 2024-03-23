


#include "bsp_esp32.h"

void bsp_init(void)
{
#if defined(TARGET_BOARD_ESP32_DEVKIT)

#elif defined(TARGET_BOARD_ESP32_8048S070c)
    bsp_8048S070C_init();
#endif
}