#include <ESP8266Wifi.h>
#include <PubSubCliente.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Buzzer.h>

#define endereco 20x07
#define linhas 4
#define colunas 20
#define DHTPIN 14
#define DHTTYPE DHT11

LiquidCrystal_I2C.lcd(endereco,linhas,colunas);
DHT dht(DHTPIN, DHTTYPE);

//Conection WIFI
const char ssid = "Nome da rede";
const char password= "Senha da rede";

void setup() {
//Configurações do DHT1
Serial.begin(115200);
dht.begin();

//Configuração do WIFI
Serial.println();
Serial.println ();
Serial.print("conectando a rede ");
Serial.println(ssid);

WiFi.begin(ssid,password);
while (WiFi.status() !=WL_CONNECTED){
delay(500);
Serial.print(".");
}

Serial.print("Usar essa URL :");
Serial.print("https://");
Serial.print(WiFi.localIP());
Serial.println("/");

//Configurações do LCD
lcd.init();
lcd.backlight();
lcd.print("Temperatura:");
lcd.setCursor(0,1);
lcd.print("Umidade:");
lcd.setCursor(0,2);
lcd.print("");
lcd.setCursor(0,3);
lcd.print("Alerta:");
}

void loop() {

float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0,2);
  lcd.print("Umidade: ");
  lcd.print(humidity);
  lcd.print(" %");

if(temperature <= 21, humidity <= 44){
  lcd.setCursor(0,3);
  lcd.print("Alerta: Muito Baixo");
  tone(6,800);
  delay(100);
  noTone(6);
  delay(100);
  delay(2000);
} else {}


if ((temperature >= 22) && (temperature <=24), (humidity >=45) && (humidity <=60)) {
    lcd.setCursor(0,3);
    lcd.print("Alerta: Suave");
    delay(2000);
    lcd.clear();
  }

if (temperature >= 25, humidity >=61){
  lcd.setCursor(0,3);
  lcd.print("Alerta: Tome cuidado");
  tone(6,800);
  delay(100);
  noTone(6);
  delay(100);
  delay(2000);
  lcd.clear();
}

  delay(2000);
}
}


