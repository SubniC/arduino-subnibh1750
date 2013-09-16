/**
 * SubniBH1750.h - Library for interacting with BH1750 light sensors
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

//Comandos del sensor BH1750
#define BH_POWER_DOWN       0x0
#define BH_POWER_ON         0x1
#define BH_RESET			0x7
#define BH_HIRES_MODE       0x10
#define BH_HIRES_MODE2      0x11
#define BH_LOWRES_MODE      0x13
#define BH_ONE_HIRES_MODE   0x20
#define BH_ONE_HIRES_MODE2  0x21
#define BH_ONE_LOWRES_MODE  0x23

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