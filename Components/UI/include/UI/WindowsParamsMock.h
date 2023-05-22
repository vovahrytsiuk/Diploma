#pragma once

#include <vector>
#include <string>

struct ButtonParams
{
    std::wstring _text;
    int _x;
    int _y;
    int _height;
    int _width;
};

struct LabelParams
{
    std::wstring _text;
    int _x;
    int _y;
    int _height;
    int _width;
};

struct LineEditParams
{
    int _x;
    int _y;
    int _height;
    int _width;
};

struct CheckBoxParams
{
    std::wstring _text;
    int _x;
    int _y;
    int _height;
    int _width;
};

struct WindowParams
{
    std::wstring _title;
    std::vector<ButtonParams> _buttons;
    std::vector<LabelParams> _labels;
    std::vector<LineEditParams> _lineEdits;
    std::vector<CheckBoxParams> _checkBoxes;
};