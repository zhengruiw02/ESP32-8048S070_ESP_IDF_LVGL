// This project was created using Espressif example (rgb_panel).
// UI for this project was created with SquareLine Studio.
// It was tested with ESP-IDF v5.1

#include "esp_log.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "lvgl.h"

#include <lv_demos.h>
#include "sdkconfig.h"
#include <stdio.h>
#include "bsp/bsp_esp32_8048S070C.h"


extern "C" {

static const char *TAG = "Sunton_ESP32-8048S070c_example";


extern void ui_init(lv_disp_t *disp);


void app_main(void) {


  bsp_init();

  ESP_LOGI(TAG, "Display simple buttons example");

  lv_demo_benchmark();
  //ui_init(bsp_lvgl_get_disp());

  while (1) {
    // raise the task priority of LVGL and/or reduce the handler period can
    // improve the performance
    vTaskDelay(pdMS_TO_TICKS(10));
    // The task running lv_timer_handler should have lower priority than that
    // running `lv_tick_inc`
    lv_timer_handler();
  }
}
}
