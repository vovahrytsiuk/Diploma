#include "Image.h"
#include <stdlib.h>
#include <time.h>
#include <string>

Image::Image()
{
	srand(time(NULL));
	name = std::to_string(rand());
}

void Image::setSizeVert(int info)
{
	sizeVert = info;
	std::cout << "Set sizeVert: " << info << " for " << name << '\n';
}

int Image::getSizeVert()
{
	return sizeVert;

}

void Image::setSizeGorz(int info)
{
	sizeGorz = info;
	std::cout << "Set sizeGorz: " << info << " for " << name << '\n';
}

int Image::getSizeGorz()
{
	return sizeGorz;
}

void Image::setPositionVert(int info)
{
	positionVert = info;
	std::cout << "Set positionVert: " << info << " for " << name << '\n';
}

int Image::getPositionVert()
{
	return positionVert;
}

void Image::setPositionGorz(int info)
{
	positionGorz = info;
	std::cout << "Set positionGorz: " << info << " for " << name << '\n';
}

int Image::getPositionGorz()
{
	return positionGorz;
}

void Image::setName(std::string info)
{
	name = info;
	std::cout << "Set name: " << info << " for " << name << '\n';
}

std::string Image::getName()
{
	return name;
}

void Image::setPath(std::string info)
{
	path = info;
	std::cout << "Set path: " << info << " for " << name << '\n';
}

std::string Image::getPath()
{
	return path;
}

