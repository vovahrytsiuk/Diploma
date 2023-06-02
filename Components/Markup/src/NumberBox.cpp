#include "NumberBox.h"
#include <stdlib.h>
#include <time.h>
#include <string>

NumberBox::NumberBox()
{
	srand(time(NULL));
	name = std::to_string(rand());
}

void NumberBox::setPositionVert(int info)
{
	positionVert = info;
	std::cout << "Set positionVert: " << info << " for " << name << '\n';
}

int NumberBox::getPositionVert()
{
	return positionVert;
}

void NumberBox::setPositionGorz(int info)
{
	positionGorz = info;
	std::cout << "Set positionGorz: " << info << " for " << name << '\n';
}

int NumberBox::getPositionGorz()
{
	return positionGorz;
}

void NumberBox::setName(std::string info)
{
	name = info;
	std::cout << "Set name: " << info << " for " << name << '\n';
}

std::string NumberBox::getName()
{
	return name;
}

void NumberBox::setMinValue(int info)
{
	minValue = info;
	std::cout << "Set minValue: " << info << " for " << name << '\n';
}

int NumberBox::setMinValue()
{
	return minValue;
}

void NumberBox::setMaxValue(int info)
{
	maxValue = info;
	std::cout << "Set maxValue: " << info << " for " << name << '\n';
}

int NumberBox::setMaxValue()
{
	return maxValue;
}

void NumberBox::setDefaultValue(int info)
{
	defaultValue = info;
	std::cout << "Set defaultValue: " << info << " for " << name << '\n';
}

int NumberBox::setDefaultValue()
{
	return defaultValue;
}

void NumberBox::setClicable(bool info)
{
	clicable = info;
	std::cout << "Set clicable " << info << "for " << name << '\n';
}

bool NumberBox::getClicable()
{
	return clicable;
}