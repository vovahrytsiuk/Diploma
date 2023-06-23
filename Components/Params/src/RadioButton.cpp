#include <Params/RadioButton.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace Params;

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

int RadioButton::getPositionVert() const
{
    return positionVert;
}

void RadioButton::setPositionGorz(int info)
{
    positionGorz = info;
    std::cout << "Set positionGorz: " << info << " for " << name << '\n';
}

int RadioButton::getPositionGorz() const
{
    return positionGorz;
}

void RadioButton::setName(std::string info)
{
    name = info;
    std::cout << "Set name: " << info << " for " << name << '\n';
}

std::string RadioButton::getName() const
{
    return name;
}

void RadioButton::setDefaultValue(bool info)
{
    defaultValue = info;
    std::cout << "Set defaultValue: " << info << " for " << name << '\n';
}

bool RadioButton::setDefaultValue() const
{
    return defaultValue;
}

void RadioButton::setGroupName(std::string info)
{
    groupName = info;
    std::cout << "Set groupName: " << info << " for " << name << '\n';
}

std::string RadioButton::getGroupName() const
{
    return groupName;
}

void RadioButton::setSizeGorz(int info)
{
    sizeGorz = info;
}

int RadioButton::getSizeGorz() const
{
    return sizeGorz;
}

void RadioButton::setSizeVert(int info)
{
    sizeVert = info;
}

int RadioButton::getSizeVert() const
{
    return sizeVert;
}