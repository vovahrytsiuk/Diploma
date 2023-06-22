#pragma once

class Position final
{
public:
    Position(int x, int y)
        : _x{x}, _y{y} {}

    int getY() const
    {
        return _y;
    }

    void setX(int x)
    {
        _x = x;
    }

    void setY(int y)
    {
        _y = y;
    }

    int getX() const
    {
        return _x;
    }

private:
    int _x;
    int _y;
};