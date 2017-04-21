# Meteostation
Метеостанции на Arduino

## Папки

**Libs** - папка с библиотеками
  
**Meteostation_RX** - прошивка для Ардуино UNO, приёмник

**Meteostation_TX** - прошивка для Ардуино Pro Mini, передатчик

**ВНИМАНИЕ! ПУТЬ К ПАПКЕ СО СКЕТЧЕМ НЕ ДОЛЖЕН СОДЕРЖАТЬ РУССКИХ СИМВОЛОВ!
ВО ИЗБЕЖАНИЕ ПРОБЛЕМ ПОЛОЖИТЕ ПАПКУ В КОРЕНЬ ДИСКА С.**

### Схема подключения передатчик, версия 0.1
![Meteostation TX 0.1](https://github.com/Alexopro/Meteostation/blob/master/Meteostation_TX_0.1.jpg)

### Схема подключения приёмника, версия 0.1
![Meteostation RX 0.1](https://github.com/Alexopro/Meteostation/blob/master/Meteostation_RX_0.1.jpg)

##  Материалы и компоненты
Ардуино
* UNO [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fstore%2Fproduct%2Fhigh-quality-UNO-R3-MEGA328P-CH340-CH340G-for-Arduino-UNO-R3-USB-CABLE%2F731260_32339945138.html) [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fstore%2Fproduct%2FUNO-R3-CH340G-ATmega328P-compatible-for-Arduino-UNO-R3%2F1950989_32523366108.html)
* Pro Mini [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fstore%2Fproduct%2FFree-Shipping-1pcs-lot-ATMEGA328P-Pro-Mini-328-Mini-ATMEGA328-5V-16MHz-for-Arduino%2F731260_32340811597.html) [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fstore%2Fproduct%2FProMini-ATmega328P-5V-Compatible-for-Arduino-Pro-Mini%2F1950989_32525859745.html) [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fstore%2Fproduct%2FFree-Shipping-new-version-2pcs-lot-Pro-Mini-328-Mini-ATMEGA328-5V-16MHz-for-Arduino%2F1022067_1731218090.html)

Выключатель
* 5 шт. [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2FI2C-SPI-GY-BMP280-3-3-Digital-Barometric-Pressure-Altitude-Sensor-High-Precision-Atmospheric-Module-for%2F32654079031.html)
* 10 шт. [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2F10pcs-lot-10-15mm-SPST-2PIN-ON-OFF-G130-Boat-Rocker-Switch-3A-250V-Car-Dash%2F32680215196.html)

DC-DC
* от 0.9В ~ 5В до 5В 600mA [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2FFree-Shipping-DC-DC-USB-Output-charger-step-up-Power-Boost-Module-0-9V-5V-to%2F32672393138.html)
* от 3В ~ 5В до 5В 1A [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2FDC-DC-Converter-Output-Step-Up-Boost-Power-Supply-Module-3V-to-5V-1A-USB-Charger%2F32583541824.html)

LCD экран с драйвером и LCD Shield
* 16X2 [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2FFreeshipping-LCD1602-LCD-monitor-1602-5V-blue-screen-and-white-code-for-ARDUINO%2F32259705766.html)
* 16X2 с драйвером [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2FSpecial-promotions-LCD-1602-module-Blue-screen-IIC-I2C-for-arduino-LCD1602-Adapter-plate%2F1967124495.html)
* Keypad Shield 16X2 [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2FFree-Shipping-LCD-Keypad-Shield-LCD1602-LCD-1602-Module-Display-for-arduino-ATMEGA328-ATMEGA2560-raspberry-pi%2F32458411471.html)
* 20X4 [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2FFree-shipping-LCD-Board-2004-20-4-LCD-20X4-5V-yellow-green-screen-LCD2004-display-LCD%2F32346783013.html)

Часы Реального Времени 
* DS1307 [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2FNew-I2C-RTC-DS1307-AT24C32-Real-Time-Clock-Module-For-AVR-ARM-PIC-Wholesale%2F32341824388.html)

Датчик атмосферного давления
* BMP085 [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fstore%2Fproduct%2F1PCS-GY-68-BMP180-Replace-BMP085-Digital-Barometric-Pressure-Sensor-Module-For-Arduino%2F731260_32346767511.html)
* BMP180(Более точный) [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2FI2C-SPI-GY-BMP280-3-3-Digital-Barometric-Pressure-Altitude-Sensor-High-Precision-Atmospheric-Module-for%2F32654079031.html)

Беспроводной модуль NRF24L01+ и адаптер питания
* Микро [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2FFree-shipping-SMD-NRF24L01-wireless-data-transmission-module-Mini-NRF24L01-wireless-module%2F32642004648.html)
* 5 шт. Обычный [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2F15927-Free-shipping-NRF24L01-NRF24L01-Wireless-Module-2-4G-Wireless-Communication-Module-Upgrade-Module%2F32354926527.html)
* С антенной [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2F1sets-Special-promotions-1100-meter-long-distance-NRF24L01-PA-LNA-wireless-modules-with-antenna%2F32341792715.html)
* Адаптер питания [ТУТ](http://alipromo.com/cashback/view/rwuc191ya3q8wyq0gbtizfro4yyxlvew/?to=https%3A%2F%2Fru.aliexpress.com%2Fitem%2FNew-Socket-Adapter-plate-Board-for-8Pin-NRF24L01-Wireless-Transceive-module-51%2F32652342305.html) 