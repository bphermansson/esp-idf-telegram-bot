#include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
#include "esp_err.h"
#include "nvs_flash.h"
#include "include/wifi_handler.h"
#include "include/rest_handler.h"

void app_main(void)
{
    //Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    wifi_init_sta();
    telegram_sendMessage("test text");
}
