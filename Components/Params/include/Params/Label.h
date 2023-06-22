#pragma once
#include <iostream>
#include "Text.h"

namespace Params
{
    class Label
    {
    public:
        Label();
        ~Label() = default;

        void setPositionVert(int info);
        int getPositionVert() const;
        void setPositionGorz(int info);
        int getPositionGorz() const;
        void setName(std::string info);
        std::string getName() const;

        Text text;

    private:
        std::string name;
        int positionVert = 0;
        int positionGorz = 0;
    };
}
