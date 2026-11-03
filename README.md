# esp-idf-telegram-bot
This is ESP-IDF code for an ESP32 that sends a message to Telegram. If you have 
the Telegram app on your phone this is an easy way to make an ESP32 send a notice to a phone.

The function to send is in `main/src/rest_handler.c` (declared in `main/include/rest_handler.h`).
Include `rest_handler.h` and send messages with `telegram_sendMessage("test text");`.
Note that messages are truncated to 49 characters.

## Reusing this code in your own project
Copy these files to your project:

- `main/src/rest_handler.c`
- `main/include/rest_handler.h`
- `main/src/http_event_handler.c`
- `main/include/http_event_handler.h`
- `main/telegram_certificate.pem`

Then:

- Embed the PEM certificate in the binary: add `telegram_certificate.pem` to `EMBED_TXTFILES` in `CMakeLists.txt`, or to `COMPONENT_EMBED_TXTFILES` in `component.mk`.
- Copy the `ESP_TELEGRAM_TOKEN` and `ESP_TELEGRAM_CHAT_ID` entries from `main/Kconfig.projbuild` into your project's Kconfig.
- Check the include in `rest_handler.c`: it uses `#include "include/http_event_handler.h"`, which assumes the `main` directory is on the include path. Change it to `#include "http_event_handler.h"` if your layout differs.

## Usage
In the Telegram app or web, search for @BotFather. Start a chat and type '/newbot', Then enter a display name (what users see) and a username (which must end in bot, e.g., my_cool_helper_bot). BotFather will reply with a new API token.
Open the ESP-IDF "Device configuration" menu (the cog icon in the VS Code ESP-IDF extension, or run `idf.py menuconfig`) and set the WiFi credentials, Telegram token and more.
Use the pen button in the app or web to create a new group. Do not add any members and give it a good name.
In Telegram, search for @my_cool_helper_bot and open it.
Press Start and send a message such as hello.
Open https://api.telegram.org/bot<TOKEN>/getUpdates
You should now see something like:
"chat":{"id":123456789,"first_name":"...","type":"private"}
Copy that id. It's negative for groups.
Set it as ESP_TELEGRAM_CHAT_ID in idf.py menuconfig, then rebuild and flash.

Based on https://github.com/antusystem/esp-idf-telegram-bot, modified by me, Copilot and OpenCode.

## License
MIT License

Copyright (c) [2026] [phermansson]

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
