/**
 * SubniBH1750.h - Library for reading the BH1750 ambient light sensor (I2C).
 */

#ifndef SubniBH1750_h
#define SubniBH1750_h

#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Wire.h>
#include <math.h>

// BH1750 instruction set
#define BH_POWER_DOWN       0x0
#define BH_POWER_ON         0x1
#define BH_RESET            0x7
#define BH_HIRES_MODE       0x10
#define BH_HIRES_MODE2      0x11
#define BH_LOWRES_MODE      0x13
#define BH_ONE_HIRES_MODE   0x20
#define BH_ONE_HIRES_MODE2  0x21
#define BH_ONE_LOWRES_MODE  0x23

// I2C address depending on the ADDR pin level
#define BH_ADDRESS_HIGH     0x5C
#define BH_ADDRESS_LOW      0x23

class SubniBH1750 {
	public:
		SubniBH1750();
		SubniBH1750(uint8_t);
		void init(uint8_t);
		void setResolution(uint8_t);
		uint16_t getLux();

	private:
		uint8_t _address;
		uint8_t _is_init;
};

#endif
