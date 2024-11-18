#include "SocialNetwork.h"

void SocialNetwork::init(std::string networkName, int minAge)
{
	_networkName = networkName;
	_profiles.init();
	_minAge = minAge;
}

void SocialNetwork::clear()
{
	_networkName.clear();
	_profiles.clear();
	_minAge = 0;
}

std::string SocialNetwork::getNetworkName() const
{
	return _networkName;
}

int SocialNetwork::getMinAge() const
{
	return _minAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < _minAge)
		return false;
	_profiles.add(profile_to_add);
	
}

std::string SocialNetwork::getWindowsDevices() const
{
    ProfileNode* profile_curr = _profiles.get_first();
    DeviceNode* device_curr = NULL;
    std::string devicesString = "";
    std::string os = "";

    while (profile_curr) 
    {
        device_curr = profile_curr->get_data().getOwner().getDevices().get_first();
        while (device_curr) 
        {
            std::string os = device_curr->get_data().getOS();

            if (os == "Windows7" || os == "Windows10" || os == "Windows11")
            {
                devicesString += "[" + std::to_string(device_curr->get_data().getID()) + ", " + os + "], ";
            }
            device_curr = device_curr->get_next(); 
        }
        profile_curr = profile_curr->get_next(); 
    }

    if (!devicesString.empty())
    {
        devicesString.pop_back();
        devicesString.pop_back();
    }

    return devicesString;
}




