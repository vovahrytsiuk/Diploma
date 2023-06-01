#pragma once

class Size final
{
public:
    Size(int height, int width)
        : _height{height}, _width{width} {}

    int getWidth() const
    {
        return _width;
    }

    int getHeight() const
    {
        return _height;
    }

private:
    int _height;
    int _width;
};