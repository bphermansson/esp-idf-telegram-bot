/* esp-idf-telegram-bot
 *
 * Author: antusystem
 * e-mail: aleantunes95@gmail.com
 * Date: 11-01-2020
 * MIT License
 * As it is described in the readme file
 *
*/

#include <string.h>
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_http_client.h"
#include "freertos/event_groups.h"

#include "include/http_event_handler.h"

/*HTTP buffer*/
#define MAX_HTTP_RECV_BUFFER 1024
#define MAX_HTTP_OUTPUT_BUFFER 2048

/* TAGs for the system*/
static const char *TAG = "HTTP_CLIENT Handler";
static const char *TAG2 = "Sending sendMessage";

/* Root cert for extracted from:
 *
 * https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot/blob/master/src/TelegramCertificate.h

   To embed it in the app binary, the PEM file is named
   in the component.mk COMPONENT_EMBED_TXTFILES variable.
*/
char url_string[512] = "https://api.telegram.org/bot";
extern const char telegram_certificate_pem_start[] asm("_binary_telegram_certificate_pem_start");
extern const char telegram_certificate_pem_end[]   asm("_binary_telegram_certificate_pem_end");

void https_telegram_sendMessage_perform_post(void) {
	char url[512] = "";
    char output_buffer[MAX_HTTP_OUTPUT_BUFFER] = {0};   // Buffer to store response of http request
    esp_http_client_config_t config = {
        .url = "https://api.telegram.org",
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
        .event_handler = _http_event_handler,
        .cert_pem = telegram_certificate_pem_start,
		.user_data = output_buffer,
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);

    strcat(url,url_string);
    strcat(url,"/sendMessage");
    //ESP_LOGW(TAG3, "url string es: %s",url);
    esp_http_client_set_url(client, url);
	char post_data[512] = "";
	sprintf(post_data,"{\"chat_id\":%s,\"text\":\"Here goes the message from post\"}",CONFIG_ESP_TELEGRAM_CHAT_ID2);
    //ESP_LOGW(TAG, "Json: %s",post_data);
    esp_http_client_set_method(client, HTTP_METHOD_POST);
    esp_http_client_set_header(client, "Content-Type", "application/json");
    esp_http_client_set_post_field(client, post_data, strlen(post_data));

    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        ESP_LOGI(TAG2, "HTTP POST Status = %d, content_length = %d",
                esp_http_client_get_status_code(client),
                esp_http_client_get_content_length(client));
        ESP_LOGW(TAG2, "Output: %s",output_buffer);

    } else {
        ESP_LOGE(TAG2, "HTTP POST request failed: %s", esp_err_to_name(err));
    }
    esp_http_client_close(client);
    esp_http_client_cleanup(client);
    //ESP_LOGI(TAG2, "esp_get_free_heap_size: %d", esp_get_free_heap_size ());
}

void http_test_task(void *pvParameters) {
    strcat(url_string,CONFIG_ESP_TELEGRAM_TOKEN);
    vTaskDelay(2000 / portTICK_PERIOD_MS);

    ESP_LOGW(TAG, "Send to Telegram");
    https_telegram_sendMessage_perform_post();
    vTaskDelete(NULL);
}