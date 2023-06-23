#pragma once
#include <iostream>

namespace Params
{
    class Text
    {
    public:
        Text() = default;
        ~Text() = default;

        void setPositionVert(int info);
        int getPositionVert() const;
        void setPositionGorz(int info);
        int getPositionGorz() const;

        void setHeight(int info);
        int getHeight() const;
        void setItalic(bool info);
        bool getItalic() const;
        void setUnderline(bool info);
        bool getUnderline() const;
        void setBold(bool info);
        bool getBold() const;

        std::string getText() const;
        void setText(std::string info);

        std::string getTitle() const;
        void setTitle(std::string info);

    private:
        int positionVert = 0;
        int positionGorz = 0;
        std::string text = "Text";

        int height = 18;
        bool italic = false;
        bool underline = false;
        bool bold = false;
        std::string title = "Calibri";
    };
}
