#include <ESP8266WiFi.h>
 
const char* ssid = "Posa";
const char* password = "posapbm08";

int port = 5152;

WiFiServer server(port);

char buffer[1024];
int count = 0;
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  // Connect to WiFi network
  Serial.println();
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
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  Serial.print("On port: ");
  Serial.println(port);
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");

  while (client.connected()) {
    while (client.available()) {
      buffer[count++] = client.read();

      if (buffer[count-1] == '\0') {
        printMessage();
        count = 0;
      }
    }
  }
}

void printMessage() {
  Serial.println(buffer);
}
