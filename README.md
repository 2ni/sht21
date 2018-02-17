# Platformio library to control SHT21 temperature and humidity
based on https://github.com/markbeee/SHT21 modified to my needs

# Usage
It can be used as follows in your sketch (main.cpp):
```
#include <sht21.h>

#define SDA_PIN 4
#define SCL_PIN 5

SHT21 SHT21(SDA_PIN, SCL_PIN);

void setup() {
  Serial.begin(115200);
  while (!Serial);

  SHT21.init();
  int ok;
  float h;
  float t;
  char ch;
  char th;
}

void loop() {
  h = SHT21.getHumidity(&ok);
  if (ok) { dtostrf(h, 3, 1, ch); } else { sprintf(ch, "-"); }

  t = SHT21.getTemperature(&ok);
  if (ok) { dtostrf(t, 3, 1, ct); } else { sprintf(ct, "-"); }

  Serial.println("humidity: %s%, temperature: %sC", ch, ct);
  delay(1000);
}
```
