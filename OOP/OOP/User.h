#include <string>
#include "Device.h"
#include "DeviceList.h"

class User
{
private:
	unsigned int _id;
	unsigned int _age;
	std::string _username;
	DevicesList _list;

public:
	void init(unsigned int id, std::string username, unsigned int age);
	void clear();
	unsigned int getID() const;
	std::string getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices();
	void addDevice(Device newDevice);
	bool checkIfDevicesAreOn() const;
};
