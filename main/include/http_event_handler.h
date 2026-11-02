#ifndef HTTP_EVENT_HANDLER_H
#define HTTP_EVENT_HANDLER_H

#include "esp_http_client.h"
#include "esp_err.h"

esp_err_t _http_event_handler(esp_http_client_event_t *evt);

#endif // HTTP_EVENT_HANDLER_H