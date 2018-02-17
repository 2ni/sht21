/*
  SHT21 - Library for ESP8266 and Arduino for the Sensirion Temperature and Humidity sensor
  based on https://github.com/markbeee/SHT21 modified to my needs

  int ok;
  h = SHT21.getHumidity(&ok);
  if(ok) {...}
*/

#include "sht21.h"

SHT21::SHT21 (int sda, int sdc) {
  mySda = sda;
  mySdc = sdc;
}

void SHT21::init() {
  Wire.begin(mySda, mySdc);
  Wire.setClock(400000);
}

float SHT21::getHumidity(int *ok) {
  return (-6.0 + 125.0 / 65536.0 * (float)(readSHT21(TRIGGER_HUMD_MEASURE_NOHOLD, ok)));
}

float SHT21::getTemperature(int *ok) {
  return (-46.85 + 175.72 / 65536.0 * (float)(readSHT21(TRIGGER_TEMP_MEASURE_NOHOLD, ok)));
}

uint16_t SHT21::readSHT21(uint8_t command, int *ok) {
  uint16_t result=0;
  byte error;
  if(ok) { *ok = 0; }

  Wire.beginTransmission(SHT21_ADDRESS);
  Wire.write(command);
  error = Wire.endTransmission();

  if (error == 0) {
    delay(100);

    Wire.requestFrom(SHT21_ADDRESS, 3);
    while(Wire.available() < 3) {
      delay(1);
    }

    // return result
    result = ((Wire.read()) << 8);
    result += Wire.read();
    result &= ~0x0003;   // clear two low bits (status bits)
    if(ok) { *ok = 1; }
  }

  return result;
}
