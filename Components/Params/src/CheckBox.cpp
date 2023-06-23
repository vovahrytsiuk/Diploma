#include <Params/CheckBox.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace Params;

CheckBox::CheckBox()
{
    srand(time(NULL));
    name = std::to_string(rand());
}

void CheckBox::setPositionVert(int info)
{
    positionVert = info;
    std::cout << "Set positionVert: " << info << " for " << name << '\n';
}

int CheckBox::getPositionVert() const
{
    return positionVert;
}

void CheckBox::setPositionGorz(int info)
{
    positionGorz = info;
    std::cout << "Set positionGorz: " << info << " for " << name << '\n';
}

int CheckBox::getPositionGorz() const
{
    return positionGorz;
}

void CheckBox::setName(std::string info)
{
    name = info;
    std::cout << "Set name: " << info << " for " << name << '\n';
}

std::string CheckBox::getName() const
{
    return name;
}

void CheckBox::setDefaultValue(bool info)
{
    defaultValue = info;
    std::cout << "Set defaultValue: " << info << " for " << name << '\n';
}

bool CheckBox::setDefaultValue() const
{
    return defaultValue;
}

void CheckBox::setClicable(bool info)
{
    clicable = info;
    std::cout << "Set clicable " << info << "for " << name << '\n';
}

bool CheckBox::getClicable() const
{
    return clicable;
}

void CheckBox::setSizeGorz(int info)
{
    sizeGorz = info;
}

int CheckBox::getSizeGorz() const
{
    return sizeGorz;
}

void CheckBox::setSizeVert(int info)
{
    sizeVert = info;
}

int CheckBox::getSizeVert() const
{
    return sizeVert;
}