#include <Wire.h>		  // библиотека для работы с интерфейсом I2C 
#include <SPI.h>          // библиотека для работы с шиной SPI
#include <BMP085.h>   	  // библиотека датчика давления
#include "nRF24L01.h"     // библиотека радиомодуля
#include "RF24.h"         // ещё библиотека радиомодуля
#define PinVBat A0		  // константа аналогово входа

BMP085 dps = BMP085();
RF24 radio(9, 10);

byte address[][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"}; //возможные номера труб
long Temperature = 0, Pressure = 0, Altitude = 0; // переменные для датчика атмосферного давления
float VBat; // переменная для наприжения аккамулятора

void setup(void) {
  Serial.begin(9600); //
  delay(1000);
  dps.init(MODE_STANDARD, 3200, true);

  radio.begin(); //активировать модуль
  radio.setAutoAck(1);         //режим подтверждения приёма, 1 вкл 0 выкл
  radio.setRetries(0, 15);    //(время между попыткой достучаться, число попыток)
  radio.enableAckPayload();    //разрешить отсылку данных в ответ на входящий сигнал
  radio.setPayloadSize(32);     //размер пакета, в байтах

  radio.openWritingPipe(address[0]);   //мы - труба 0, открываем канал для передачи данных
  radio.setChannel(0x60);  //выбираем канал (в котором нет шумов!)

  radio.setPALevel (RF24_PA_MAX); //уровень мощности передатчика. На выбор RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setDataRate (RF24_250KBPS); //скорость обмена. На выбор RF24_2MBPS, RF24_1MBPS, RF24_250KBPS
  //должна быть одинакова на приёмнике и передатчике!
  //при самой низкой скорости имеем самую высокую чувствительность и дальность!!

  radio.powerUp(); //начать работу
  radio.stopListening();  //не слушаем радиоэфир, мы передатчик

}
long data[3];
void loop(void) {
  dps.getPressure(&Pressure);
  dps.getTemperature(&Temperature);
  dps.getAltitude(&Altitude);
  VBat = (analogRead(PinVBat)) * 5.15 / 1024.0;
  /*
  Serial.println(VBat);
  Serial.print("Pressure(mmHg):");
  Serial.print(Pressure / 133.3);    //Выводим давление в мм.рт ст
  Serial.print(" Temp:");
  Serial.print(Temperature * 0.1); // Температуру в градусах Цельсия
  Serial.print(" Altitude:");
  Serial.println(Altitude / 100.0, 2); // высота в метрах
  */
  data[0] = Pressure;
  delay(50);
  data[1] = Temperature;
  delay(50);
  data[2] = VBat * 100.0;
  delay(50);
  radio.write(&data, sizeof(data));
  delay(15000);
}
