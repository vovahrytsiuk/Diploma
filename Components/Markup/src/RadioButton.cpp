#include "RadioButton.h"
#include <stdlib.h>
#include <time.h>
#include <string>

RadioButton::RadioButton()
{
	srand(time(NULL));
	name = std::to_string(rand());
}

void RadioButton::setPositionVert(int info)
{
	positionVert = info;
	std::cout << "Set positionVert: " << info << " for " << name << '\n';
}

int RadioButton::getPositionVert()
{
	return positionVert;
}

void RadioButton::setPositionGorz(int info)
{
	positionGorz = info;
	std::cout << "Set positionGorz: " << info << " for " << name << '\n';
}

int RadioButton::getPositionGorz()
{
	return positionGorz;
}

void RadioButton::setName(std::string info)
{
	name = info;
	std::cout << "Set name: " << info << " for " << name << '\n';
}

std::string RadioButton::getName()
{
	return name;
}

void RadioButton::setDefaultValue(bool info)
{
	defaultValue = info;
	std::cout << "Set defaultValue: " << info << " for " << name << '\n';
}

bool RadioButton::setDefaultValue()
{
	return defaultValue;
}

void RadioButton::setGroupName(std::string info)
{
	groupName = info;
	std::cout << "Set groupName: " << info << " for " << name << '\n';
}

std::string RadioButton::getGroupName()
{
	return groupName;
}
