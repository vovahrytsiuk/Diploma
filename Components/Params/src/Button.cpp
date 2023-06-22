#include <Params/Button.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace Params;

Button::Button()
{
    srand(time(NULL));
    name = std::to_string(rand());
}

void Button::setSizeVert(int info)
{
    sizeVert = info;
    std::cout << "Set sizeVert: " << info << " for " << name << '\n';
}

int Button::getSizeVert() const
{
    return sizeVert;
}

void Button::setSizeGorz(int info)
{
    sizeGorz = info;
    std::cout << "Set sizeGorz: " << info << " for " << name << '\n';
}

int Button::getSizeGorz() const
{
    return sizeGorz;
}

void Button::setPositionVert(int info)
{
    positionVert = info;
    std::cout << "Set positionVert: " << info << " for " << name << '\n';
}

int Button::getPositionVert() const
{
    return positionVert;
}

void Button::setPositionGorz(int info)
{
    positionGorz = info;
    std::cout << "Set positionGorz: " << info << " for " << name << '\n';
}

int Button::getPositionGorz() const
{
    return positionGorz;
}

void Button::setName(std::string info)
{
    name = info;
    std::cout << "Set name: " << info << " for " << name << '\n';
}

std::string Button::getName() const
{
    return name;
}

void Button::setClicable(bool info)
{
    clicable = info;
    std::cout << "Set clicable " << info << "for " << name << '\n';
}

bool Button::getClicable() const
{
    return clicable;
}

void Button::setDoubleClicable(bool info)
{
    doubleClicable = info;
    std::cout << "Set doubleClicable " << info << "for " << name << '\n';
}

bool Button::getDoubleClicable() const
{
    return doubleClicable;
}