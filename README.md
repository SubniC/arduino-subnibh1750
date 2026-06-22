# SubniBH1750

Arduino library to read ambient light (lux) from the **BH1750** I2C light sensor.

> **Legacy library (2013).** Kept for reference; docs refreshed in 2026, library
> behavior unchanged.

## Features

- Reads illuminance in lux with `getLux()`.
- Selectable measurement mode/resolution via `setResolution()`.
- Supports both I2C addresses (`BH_ADDRESS_HIGH` 0x5C, `BH_ADDRESS_LOW` 0x23).
- Tiny footprint, no dynamic allocation.

## Dependencies

Uses the Arduino [`Wire`](https://www.arduino.cc/en/reference/wire) library for I2C
(bundled with the Arduino IDE). No external libraries required.

## Installation

- **Manual**: copy this folder into your Arduino `libraries/` directory and restart
  the IDE.
- **PlatformIO**: add the repository to `lib_deps`.

## Usage

```cpp
#include <Wire.h>
#include <SubniBH1750.h>

// BH1750 at the low I2C address (ADDR pin low / floating)
SubniBH1750 lightSensor(BH_ADDRESS_LOW);

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  Serial.print("Light: ");
  Serial.print(lightSensor.getLux());
  Serial.println(" lux");
  delay(1000);
}
```

See [`examples/BasicReading`](examples/BasicReading) for the full sketch.

## API

```cpp
SubniBH1750();                    // create uninitialized; call init() later
SubniBH1750(uint8_t address);     // create and initialize at the given I2C address

void init(uint8_t address);       // set address, switch to hi-res mode, mark ready
void setResolution(uint8_t mode); // send a BH1750 mode command (BH_HIRES_MODE, ...)
uint16_t getLux();                // return illuminance in lux (0 if not initialized)
```

## License

[MIT](LICENSE) © 2013–2026 mdps

---

_Un proyecto de mdps · 2026 · desarrollado en Murcia._
