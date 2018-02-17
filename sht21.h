/*
  SHT21 - Library for ESP8266 and Arduino for the Sensirion Temperature and Humidity sensor
  https://github.com/markbeee/SHT21

  modified to my needs
*/

#ifndef SHT21_H
#define SHT21_H

#include <ESP8266WiFi.h>
#include <Wire.h>

#define SHT21_ADDRESS 0x40  //I2C address for the sensor

#define TRIGGER_TEMP_MEASURE_NOHOLD  0xF3
#define TRIGGER_HUMD_MEASURE_NOHOLD  0xF5

class SHT21 {

private:
  int mySda;
  int mySdc;

  uint16_t readSHT21(uint8_t command, int *ok);

public:
  SHT21(int sda, int sdc);

  void init(void);
  float getHumidity(int *ok);
  float getTemperature(int *ok);

};

#endif
