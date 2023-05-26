#include "DHT.h"
#define dht_type DHT11

int dht_pin = A1;
DHT dht_1 = DHT(dht_pin, dht_type);
int lm35_pin = A0, leitura_lm35 = 0;
float temperatura;
int ldr_pin = A5, leitura_ldr = 0;
int switch_pin = 7;
void setup()
{
  Serial.begin(9600);
  dht_1.begin();
  pinMode(switch_pin, INPUT);
}
void loop()
{

  float UmidadeReal = dht_1.readHumidity();
  float TemperaturaReal = dht_1.readTemperature();

  if (isnan(TemperaturaReal) or isnan(UmidadeReal))
  {
    Serial.println("Erro ao ler o DHT");
  }
  else
  {
    Serial.print(UmidadeReal);
    Serial.print(";");
    Serial.println(TemperaturaReal);

   }
  delay(5000);
}
