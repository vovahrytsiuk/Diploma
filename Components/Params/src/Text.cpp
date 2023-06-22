#include <Params/Text.h>

using namespace Params;

void Text::setPositionVert(int info)
{
    positionVert = info;
    std::cout << "Set positionVert: " << info << " for " << text << '\n';
}

int Text::getPositionVert() const
{
    return positionVert;
}

void Text::setPositionGorz(int info)
{
    positionGorz = info;
    std::cout << "Set positionGorz: " << info << " for " << text << '\n';
}

int Text::getPositionGorz() const
{
    return positionGorz;
}

void Text::setHeight(int info)
{
    height = info;
    std::cout << "Set height: " << info << " for " << text << '\n';
}

int Text::getHeight() const
{
    return height;
}

void Text::setItalic(bool info)
{
    italic = info;
    std::cout << "Set italic " << info << "for " << text << '\n';
}

bool Text::getItalic() const
{
    return italic;
}

void Text::setUnderline(bool info)
{
    underline = info;
    std::cout << "Set underline " << info << "for " << text << '\n';
}

bool Text::getUnderline() const
{
    return underline;
}

void Text::setBold(bool info)
{
    bold = info;
    std::cout << "Set bold " << info << "for " << text << '\n';
}

bool Text::getBold() const
{
    return bold;
}

std::string Text::getText() const
{
    return text;
}

void Text::setText(std::string info)
{
    text = info;
    std::cout << "Set text: " << info << " for " << text << '\n';
}

std::string Text::getTitle() const
{
    return title;
}

void Text::setTitle(std::string info)
{
    title = info;
    std::cout << "Set title: " << info << " for " << text << '\n';
}