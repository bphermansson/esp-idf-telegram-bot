/* esp-idf-telegram-bot
 *
 * Author: antusystem
 * e-mail: aleantunes95@gmail.com
 * Date: 11-01-2020
 * MIT License
 * As it is described in the readme file
 *
*/

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
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

    xTaskCreatePinnedToCore(&http_test_task, "http_test_task", 8192*4, NULL, 5, NULL,1);

}
