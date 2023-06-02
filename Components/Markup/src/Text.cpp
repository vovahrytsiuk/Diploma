#include "Text.h"

void Text::setPositionVert(int info)
{
	positionVert = info;
	std::cout << "Set positionVert: " << info << " for " << text << '\n';

}

int Text::getPositionVert()
{
	return positionVert;
}

void Text::setPositionGorz(int info)
{
	positionGorz = info;
	std::cout << "Set positionGorz: " << info << " for " << text << '\n';
}

int Text::getPositionGorz()
{
	return positionGorz;
}

void Text::setHeight(int info)
{
	height = info;
	std::cout << "Set height: " << info << " for " << text << '\n';
}

int Text::getHeight()
{
	return height;
}

void Text::setItalic(bool info)
{
	italic = info;
	std::cout << "Set italic " << info << "for " << text << '\n';
}

bool Text::getItalic()
{
	return italic;
}

void Text::setUnderline(bool info)
{
	underline = info;
	std::cout << "Set underline " << info << "for " << text << '\n';
}

bool Text::getUnderline()
{
	return underline;
}

void Text::setBold(bool info)
{
	bold = info;
	std::cout << "Set bold " << info << "for " << text << '\n';
}

bool Text::getBold()
{
	return bold;
}

std::string Text::getText()
{
	return text;
}

void Text::setText(std::string info)
{
	text = info;
	std::cout << "Set text: " << info << " for " << text << '\n';
}

std::string Text::getTitle()
{
	return title;
}

void Text::setTitle(std::string info)
{
	title = info;
	std::cout << "Set title: " << info << " for " << text << '\n';
}
