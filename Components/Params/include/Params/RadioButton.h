#pragma once
#include <iostream>
#include "Text.h"

namespace Params
{
    class RadioButton
    {
    public:
        RadioButton();
        ~RadioButton() = default;

        void setPositionVert(int info);
        int getPositionVert() const;
        void setPositionGorz(int info);
        int getPositionGorz() const;
        void setName(std::string info);
        std::string getName() const;
        void setDefaultValue(bool info);
        bool setDefaultValue() const;
        void setGroupName(std::string info);
        std::string getGroupName() const;
        void setSizeVert(int info);
        int getSizeVert() const;
        void setSizeGorz(int info);
        int getSizeGorz() const;

        Text text;

    private:
        std::string name;
        std::string groupName = "RB";
        int positionVert = 0;
        int positionGorz = 0;
        int sizeVert = 0;
        int sizeGorz = 0;
        bool defaultValue = false;
    };
}