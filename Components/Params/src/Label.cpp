#include <Params/Label.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace Params;

Label::Label()
{
    srand(time(NULL));
    name = std::to_string(rand());
}

void Label::setPositionVert(int info)
{
    positionVert = info;
    std::cout << "Set positionVert: " << info << " for " << name << '\n';
}

int Label::getPositionVert() const
{
    return positionVert;
}

void Label::setPositionGorz(int info)
{
    positionGorz = info;
    std::cout << "Set positionGorz: " << info << " for " << name << '\n';
}

int Label::getPositionGorz() const
{
    return positionGorz;
}

void Label::setName(std::string info)
{
    name = info;
    std::cout << "Set name: " << info << " for " << name << '\n';
}

std::string Label::getName() const
{
    return name;
}

void Label::setSizeGorz(int info)
{
    sizeGorz = info;
}

int Label::getSizeGorz() const
{
    return sizeGorz;
}

void Label::setSizeVert(int info)
{
    sizeVert = info;
}

int Label::getSizeVert() const
{
    return sizeVert;
}