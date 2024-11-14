// Include necessary libraries
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// Blynk credentials
#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "WEATHER MONITORING"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

// WiFi credentials
char ssid[] = "Your_WiFi_SSID";
char pass[] = "Your_WiFi_Password";

// Initialize LCD and DHT11
LiquidCrystal_I2C lcd(0x3F, 16, 2); // Change 0x3F to 0x27 if LCD doesn't display
DHT dht(D3, DHT11); // Connect DHT11 to pin D3
BlynkTimer timer;

void weather() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int rainValue = analogRead(A0); // Rain sensor connected to A0
  bool lightStatus = digitalRead(D4); // LDR connected to D4
  rainValue = map(rainValue, 0, 1023, 100, 0); // Map rain values for easy interpretation

  // Check if reading is valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Send data to Blynk
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, rainValue);

  // Update LCD display
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(humidity);
  lcd.setCursor(9, 0);
  lcd.print("R:");
  lcd.print(rainValue);
  lcd.setCursor(9, 1);
  lcd.print("L:");
  lcd.print(lightStatus ? "Low" : "High");
}

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, weather); // Update weather every second
}

void loop() {
  Blynk.run();
  timer.run();
}
