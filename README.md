# nocemcu-esp8266-alarmuino
Warning message for when an alarm is triggered in a home alarm system via Telegram

The need arose to know when the alarm is triggered in case I'm away from home. I know there are alarms that have this feature built in, but paying for cell phone service isn't the best option, so I came up with the idea of ​​using the Telegram API to send me messages over the internet. The overall project would have cost around 9,000 pesos at most, with the NodeMCU ESP8266 device (the simplest chip I found) being the most expensive. Simple to install and program, I started with MicroPython, but when I realized I was having trouble sending messages via Telegram, I created it in Arduino and it worked the first time.
