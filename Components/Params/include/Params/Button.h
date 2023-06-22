#pragma once
#include <iostream>
#include "Text.h"

namespace Params
{
    class Button
    {
    public:
        Button();
        ~Button() = default;

        void setSizeVert(int info);
        int getSizeVert() const;
        void setSizeGorz(int info);
        int getSizeGorz() const;
        void setPositionVert(int info);
        int getPositionVert() const;
        void setPositionGorz(int info);
        int getPositionGorz() const;
        void setName(std::string info);
        std::string getName() const;
        void setClicable(bool info);
        bool getClicable() const;
        void setDoubleClicable(bool info);
        bool getDoubleClicable() const;

        Text text;

    private:
        std::string name;
        int sizeVert = 72;
        int sizeGorz = 120;
        int positionVert = 0;
        int positionGorz = 0;

        bool clicable = false;
        bool doubleClicable = false;
    };
}