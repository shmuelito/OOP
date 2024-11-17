#include <iostream>
#include "Device.h"

void Device::init(unsigned int id, DeviceType type, std::string os)
{
	_id = id;
	_type = type;
	_os = os;
	_active = true;
}


unsigned int Device::getID() 
{
	return _id;
}

DeviceType Device::getType() 
{
	return _type;
}

std::string Device::getOS() 
{
	return _os;
}

bool Device::isActive() 
{
	return _active;
}

void Device::activate()
{
	_active = true;
}

void Device::deactivate()
{
	_active = false;
}