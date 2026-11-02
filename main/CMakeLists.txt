# Embed the server root certificate into the final binary
#
# (If this was a component, we would set COMPONENT_EMBED_TXTFILES here.)
idf_component_register(SRCS main.c src/wifi_handler.c src/rest_handler.c src/http_event_handler.c
                    INCLUDE_DIRS "." "include"
                    EMBED_TXTFILES telegram_certificate.pem)