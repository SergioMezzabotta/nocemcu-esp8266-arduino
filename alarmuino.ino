#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// Configuración del WIFI
const char* ssid = "nombre del WIFI";
const char* password = "contraseña del WIFI";

// Configuración de Telegram
const char* botToken = "TOKEN DEL BOTO";
// En mi caso necesitaba que los mensajes se mandaran a 2 chat ids distintos
const char* chat_id_1 = "CHAT AL QUE MANDAR LOS MENSAJES";
const char* chat_id_2 = "CHAT AL QUE MANDAR LOS MENSAJES";

WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  client.setInsecure();

  sendTelegramMessages();
}

void sendTelegramMessages() {
  String message = "¡ALERTA LA ALARMA SE HA DISPARADO!";
  
  for (int i = 0; i < 3; i++) {
    bot.sendMessage(chat_id_1, message, "");
    bot.sendMessage(chat_id_2, message, "");
    delay(2000);
  }
}