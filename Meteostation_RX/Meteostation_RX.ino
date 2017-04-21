#include <iarduino_RTC.h>
#include <Wire.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
RF24 radio(2, 3);
iarduino_RTC time(RTC_DS1307);

byte address[][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"}; //возможные номера труб

byte D[8] = //Буква Д
{
  B01110,
  B01010,
  B01010,
  B01010,
  B01010,
  B11111,
  B10001,
  B00000,
};

byte I[8] = //Буква И
{
  B10001,
  B10001,
  B10011,
  B10101,
  B11001,
  B10001,
  B10001,
  B00000,
};

byte Bat0[8] = {
  0b01110,
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111
};

byte Bat1[8] = {
  0b01110,
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b11111
};

byte Bat2[8] = {
  0b01110,
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111
};

byte Bat3[8] = {
  0b01110,
  0b11111,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte Bat4[8] = {
  0b01110,
  0b11111,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte Bat5[8] = {
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte Hour = 0;
byte Minute = 0;
byte Day = 0;
byte Month = 0;
int Year = 0;
byte cur = 0;
byte setcur = 0;


void setup() {
  Serial.begin(9600);
  delay(200);
  lcd.begin(16, 2);
  lcd.clear();
  radio.begin(); //активировать модуль
  radio.setAutoAck(1);         //режим подтверждения приёма, 1 вкл 0 выкл
  radio.setRetries(0, 15);    //(время между попыткой достучаться, число попыток)
  radio.enableAckPayload();    //разрешить отсылку данных в ответ на входящий сигнал
  radio.setPayloadSize(32);     //размер пакета, в байтах

  radio.openReadingPipe(1, address[0]);     //хотим слушать трубу 0
  radio.setChannel(0x60);  //выбираем канал (в котором нет шумов!)

  radio.setPALevel (RF24_PA_MAX); //уровень мощности передатчика. На выбор RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setDataRate (RF24_250KBPS); //скорость обмена. На выбор RF24_2MBPS, RF24_1MBPS, RF24_250KBPS
  //должна быть одинакова на приёмнике и передатчике!
  //при самой низкой скорости имеем самую высокую чувствительность и дальность!!

  radio.powerUp(); //начать работу
  radio.startListening();  //начинаем слушать эфир, мы приёмный модуль
  lcd.createChar (1, D); //Буква Д

  time.begin();
  delay(5);
  time.gettime();
  Hour = time.Hours;
  Minute = time.minutes;
  Day = time.day;
  Month = time.month;
  Year = time.year;
}

byte Key()
{
  if (analogRead(0) < 10) return 3;// право
  else if (analogRead(0) < 140) return 2;// на верх
  else if (analogRead(0) < 310) return 4;// в низ
  else if (analogRead(0) < 490) return 1;// на лево
  else if (analogRead(0) < 730) return 5;// выбор
  else if (analogRead(0) < 1023) return 0;
  delay(100);
}

void loop() {

  byte pipeNo;
  long data[3];

  float Temperature , Pressure , VBat;
  // Serial.println(time.gettime("d:m:Y, H:i:s, D"));
  //Serial.println(time.gettime("y"));
  lcd.createChar (2, Bat0); //
  lcd.createChar (3, Bat1); //
  lcd.createChar (4, Bat2); //
  lcd.createChar (5, Bat3); //
  lcd.createChar (6, Bat4); //
  lcd.createChar (7, Bat5); //

  //time.settime(-1, -1, -1, 1, 1, 17);
  if (time.year == 17) {

    lcd.setCursor(0, 0);
    lcd.print(time.gettime("H:i   d/m/y"));
    while ( radio.available(&pipeNo))  { // проверяем не пришло ли чего в буфер.
      delay(20);
      radio.read(&data, sizeof(data));// читаем данные, указываем сколько байт читать
      delay(20);
      Pressure = data[0];
      delay(50);
      Temperature = data[1];
      delay(50);
      VBat = data[2];
      delay(50);
      // Serial.println(Pressure / 133.3);      //Выводим давление в мм.рт ст

      //Serial.println(Temperature * 0.1);
      // /*
      VBat = VBat / 100.0;
      lcd.setCursor(0, 1);
      //lcd.print("Pre.");
      lcd.print(Pressure / 133.3);
      lcd.print("  ");
      //lcd .print(" Temp:");
      lcd.print(Temperature * 0.1);
      lcd.print("C  ");
      lcd.setCursor(15, 1);

      if (VBat <= 3.50)
      {
        lcd.print("\2");

      }
      else if (VBat <= 3.60) lcd.print("\3"); //
      else if (VBat <= 3.70) lcd.print("\4"); //
      else if (VBat <= 3.80) lcd.print("\5"); //
      else if (VBat <= 3.90) lcd.print("\6"); //
      else if (VBat >= 4.0) lcd.print("\7"); //

      Serial.print("Pressure(mmHg):");
      Serial.print(Pressure / 133.3);    //Выводим давление в мм.рт ст
      Serial.print(" Temp:");
      Serial.println(Temperature * 0.1);
      Serial.print(" V:");
      Serial.println(VBat);
      //
    }
  }
  else {
    lcd.setCursor(0, 0);

    lcd.print("BBE\1\2TE BPEMI");
    lcd.setCursor(0, 1);

    lcd.print(Hour);
    lcd.print(':');
    lcd.print(Minute);
    lcd.print(' ');
    lcd.print(Day);
    lcd.print(':');
    lcd.print(Month);
    lcd.print(':');
    lcd.print(Year);

    if (cur == 0) time.blinktime(3);
    if (cur == 1) time.blinktime(2);
    if (cur == 2) time.blinktime(4);
    if (cur == 3) time.blinktime(5);
    if (cur == 4) time.blinktime(6);
  }



  switch (Key())
  {
    case 1:// на лево
      cur--; delay (200);


      break;
    case 2:// на верх

      if (cur == 0) Hour++;
      else if (cur == 1) Minute++;
      else if (cur == 2) Day++;
      else if (cur == 3) Month++;
      else if (cur == 4) Year++;

      delay (500);
      break;
    case 3:// право
      cur++; delay (200);
      break;

    case 4:// в низ
      if (cur == 0) Hour--;
      else if (cur == 1) Minute--;
      else if (cur == 2) Day--;
      else if (cur == 3) Month--;
      else if (cur == 4) Year--;
      break;
    case 5:
      if (cur == 4)
        time.settime(0, Minute, Hour, Day, Month, Year);
      break;
  }

  delay(1000);

}

