#include <Params/EditLine.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace Params;

EditLine::EditLine()
{
    srand(time(NULL));
    name = std::to_string(rand());
}

void EditLine::setSizeVert(int info)
{
    sizeVert = info;
    std::cout << "Set sizeVert: " << info << " for " << name << '\n';
}

int EditLine::getSizeVert() const
{
    return sizeVert;
}

void EditLine::setSizeGorz(int info)
{
    sizeGorz = info;
    std::cout << "Set sizeGorz: " << info << " for " << name << '\n';
}

int EditLine::getSizeGorz() const
{
    return sizeGorz;
}

void EditLine::setPositionVert(int info)
{
    positionVert = info;
    std::cout << "Set positionVert: " << info << " for " << name << '\n';
}

int EditLine::getPositionVert() const
{
    return positionVert;
}

void EditLine::setPositionGorz(int info)
{
    positionGorz = info;
    std::cout << "Set positionGorz: " << info << " for " << name << '\n';
}

int EditLine::getPositionGorz() const
{
    return positionGorz;
}

void EditLine::setName(std::string info)
{
    name = info;
    std::cout << "Set name: " << info << " for " << name << '\n';
}

std::string EditLine::getName() const
{
    return name;
}

void EditLine::setMultiline(bool info)
{
    multiline = info;
    std::cout << "Set name: " << info << " for " << name << '\n';
}

bool EditLine::getMultiline() const
{
    return multiline;
}