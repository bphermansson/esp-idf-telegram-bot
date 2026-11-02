# esp-idf-telegram-bot

In the Telegram app or web, search for @BotFather. Start a chat and type '/newbot', Then enter a display name (what users see) and a username (which must end in bot, e.g., my_cool_helper_bot). BotFather will reply with a new API token.
Click the cog below and set Wifi credentials, Telegram token and more under 'Device configuration'.
Use the pen button in the app or web to create a new group. Do not add any members and give it a good name.
In Telegram, search for @my_cool_helper_bot and open it.
Press Start and send a message such as hello.
Open https://api.telegram.org/bot<TOKEN>/getUpdates
You should now see something like:
"chat":{"id":123456789,"first_name":"...","type":"private"}
Copy that id. It's negative for groups.
Set it as ESP_TELEGRAM_CHAT_ID2 in idf.py menuconfig, then rebuild and flash.

Based on https://github.com/antusystem/esp-idf-telegram-bot.

## License
MIT License

Copyright (c) [2026] [phermansson]

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
