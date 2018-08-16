/* =====================================================
 *        LEITURA DE TEMPERATURA E HUMIDADE
 * =====================================================
 * BIBLIOTECA ------- DHT
 * SENSOR ----------- DHT11
 * TEMPO DE LEITURA - 1H (UMA HORA)
 * =====================================================
 * AUTOR ------------ AMÍLCAR BORJA
 * DATA ------------- 29 DE JULHO DE 2018
 * =====================================================
 */

#include "DHT.h"

#define DHTPIN 2 // porta digital que será conectada
#define DHTTYPE DHT11 // tipo de Sensor DHT

DHT MyDHT(DHTPIN, DHTTYPE); // criada e instanciada a classe DHT


void setup() {
  Serial.begin(9600); // serial em 9600 baud rate
  Serial.println("= LEITURA DE TEMPERATURA E HUMIDADE COM DHT11! =");
  MyDHT.begin();

}

void loop() {
  float h = MyDHT.readHumidity();         // Leitura da humidade
  float tC = MyDHT.readTemperature();     // Leitura da temperatura em Celsius 
  float tF = MyDHT.readTemperature(true); // Leitura da temperatura em Fahrenheit

  // Verificar se houve falha na leitura de dados
  if (isnan(h) || isnan(tC) || isnan(tF)) {
    Serial.println("ERRO: Falha na leitura de dados do DHT11");
    return;
  }

  // Calcular o indíce de calor em Celsius
  float icc = MyDHT.computeHeatIndex(tC, h, false);
  // Calcular o index do calor em Fahrenheit
  float icf = MyDHT.computeHeatIndex(tF, h, true);

  Serial.print("Humidade: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(tC);
  Serial.print(" *C ");
  Serial.print(tF);
  Serial.print(" *F\t");
  Serial.print("Índice de Calor: ");
  Serial.print(icc);
  Serial.print(" *C ");
  Serial.print(icf);
  Serial.println(" *F");

  // Intervalo de tempo da leiruta de dados - Uma Hora (60 * 60 * 1000)
  delay(3600000);
}
