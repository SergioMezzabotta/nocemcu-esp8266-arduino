#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// Wi-Fi Configuration
const char* ssid = "Wi-Fi_name";
const char* password = "Wi-Fi_password";

// Telegram Configuration
const char* botToken = "BOT_TOKEN";
// In my case, I needed messages to be sent to two different chat IDs.
const char* chat_id_1 = "CHAT_TO_SEND_MESSAGES_TO";
const char* chat_id_2 = "CHAT_TO_SEND_MESSAGES_TO";

WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

void setup() {
Serial.begin(115200);
delay(10);

Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  client.setInsecure();

  sendTelegramMessages();
}

void sendTelegramMessages() {
  String message = "ALERT THE ALARM HAS BEEN TRIGGERED!";
  
  for (int i = 0; i < 3; i++) {
    bot.sendMessage(chat_id_1, message, "");
    bot.sendMessage(chat_id_2, message, "");
    delay(2000);
  }
}
