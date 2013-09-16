/**
 * SubniBH1750.h - Library for interacting with BH1750 light sensors
 * 
 */

#include "SubniBH1750.h"
	
/**
 * Returns the temperature in kelvin for the given resistance value
 * using the Steinhart-Hart polynom.
 */
SubniBH1750::SubniBH1750(uint8_t address)
{
	_address = address;
	setResolution(BH_HIRES_MODE);
	delay(200);
}

uint16_t SubniBH1750::getLux() 
{
  uint8_t i=0;
  uint8_t buff[2];
  Wire.beginTransmission(address);
  Wire.requestFrom(address, 2);
  while(Wire.available()) //
  {
    buff[i] = Wire.receive();  // receive one byte
    i++;
  }
  Wire.endTransmission();  
  
  if(2==i)
  {
	return (uint16_t)round(((buff[0]<<8)|buff[1])/1.2);
  }
  //TODO: Esto tendriamos que controlarlo como un error
  return 0;
}

void SubniBH1750::setResolution(uint8_t res)
{
	Wire.beginTransmission(_address);
	Wire.send(res);
	Wire.endTransmission();
}