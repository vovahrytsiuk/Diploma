#pragma once
#pragma once
#include <iostream>
#include "Text.h"

namespace Params
{
    class NumberBox
    {
    public:
        NumberBox();
        ~NumberBox() = default;

        void setPositionVert(int info);
        int getPositionVert() const;
        void setPositionGorz(int info);
        int getPositionGorz() const;
        void setName(std::string info);
        std::string getName() const;
        void setMinValue(int info);
        int getMinValue() const;
        void setMaxValue(int info);
        int getMaxValue() const;
        void setDefaultValue(int info);
        int getDefaultValue() const;
        void setClicable(bool info);
        bool getClicable() const;

        Text text;

    private:
        std::string name;
        int positionVert = 0;
        int positionGorz = 0;
        int minValue = 0;
        int maxValue = 12;
        int defaultValue = 0;
        bool clicable = false;
    };
}