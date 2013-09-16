/**
 * SubniBH1750.h - Library for interacting with BH1750 light sensors
 * 
 */

#include "SubniBH1750.h"
	
SubniBH1750::SubniBH1750()
{
	_is_init = 0x00;
	_address = 0x00;
}

SubniBH1750::SubniBH1750(uint8_t address)
{
	_is_init = 0x00;
	_address = 0x00;
	init(address);
}

void SubniBH1750::init(uint8_t address)
{
	_address = address;
	setResolution(BH_HIRES_MODE);
	_is_init = 0xFF;
	delay(200);
}

uint16_t SubniBH1750::getLux() 
{
  uint8_t i=0;
  uint8_t buff[2];
 
  if(_is_init == 0x00)
  {
    //TODO: Error, deberia poder notificarse
	//No esta inicializado	
	return 0;
  }

  Wire.beginTransmission(_address);
  Wire.requestFrom(_address, (uint8_t)2);
  while(Wire.available()) //
  {
    buff[i] = Wire.read();  // receive one byte
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
	Wire.write(res);
	Wire.endTransmission();
}