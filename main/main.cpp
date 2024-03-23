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
#include "bsp/bsp_esp32.h"

// for console_wifi & console_ping
#include "esp_netif.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_event.h"
// for console_wifi
#include "console_wifi.h"
// for console_ping
#include "console_ping.h"

extern "C" {

static const char *TAG = "MIAN";

#ifdef TARGET_HAVE_LVGL
extern void ui_init(lv_disp_t *disp);
#endif

void init_netif_nvs_flash(void)
{
  ESP_ERROR_CHECK(esp_netif_init());
  ESP_ERROR_CHECK(esp_event_loop_create_default());
  esp_err_t ret = nvs_flash_init();   //Initialize NVS
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(ret);
}

void console_init(void)
{
  ESP_ERROR_CHECK(console_cmd_init());     // Initialize console

  // Register all plugin command added to your project
  ESP_ERROR_CHECK(console_cmd_all_register());

  // To register only wifi command skip calling console_cmd_all_register()
  ESP_ERROR_CHECK(console_cmd_wifi_register());
  
  // To register only ifconfig command skip calling console_cmd_all_register()
  ESP_ERROR_CHECK(console_cmd_ping_register());

  ESP_ERROR_CHECK(console_cmd_start());    // Start console
}


void app_main(void) {


  bsp_init();

  init_netif_nvs_flash();
  console_init();

#ifdef TARGET_HAVE_LVGL
  ESP_LOGI(TAG, "Display simple buttons example");
  // lv_demo_benchmark();
  ui_init(bsp_lvgl_get_disp());
#endif


  while (1) {
    // raise the task priority of LVGL and/or reduce the handler period can
    // improve the performance
    vTaskDelay(pdMS_TO_TICKS(10));
    // The task running lv_timer_handler should have lower priority than that
    // running `lv_tick_inc`
#ifdef TARGET_HAVE_LVGL
    lv_timer_handler();
#endif
  }
}
}
