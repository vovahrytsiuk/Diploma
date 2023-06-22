#pragma once

class Size final
{
public:
    Size() {}
    Size(int height, int width)
        : _height{height}, _width{width} {}

    int getWidth() const
    {
        return _width;
    }

    void setHeight(int height)
    {
        _height = height;
    }

    void setWidth(int width)
    {
        _width = width;
    }

    int getHeight() const
    {
        return _height;
    }

private:
    int _height;
    int _width;
};