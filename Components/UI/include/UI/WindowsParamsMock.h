#pragma once

#include <vector>
#include <string>

struct ButtonParams
{
    std::string _name;
    std::string _text;
    int _x;
    int _y;
    int _height;
    int _width;
};

struct LabelParams
{
    std::string _name;
    std::string _text;
    int _x;
    int _y;
    int _height;
    int _width;
};

struct FieldEditParams
{
    std::string _name;
    int _x;
    int _y;
    int _height;
    int _width;
};

struct CheckBoxParams
{
    std::string _name;
    std::string _text;
    int _x;
    int _y;
    int _height;
    int _width;
};

struct SpinBoxParams
{
    std::string _name;
    int _x;
    int _y;
    int _height;
    int _width;
    int _upper;
    int _lower;
    int _default;
};

struct WindowParams
{
    std::string _title;
    int _height;
    int _width;
    std::vector<ButtonParams> _buttons;
    std::vector<LabelParams> _labels;
    std::vector<FieldEditParams> _lineEdits;
    std::vector<CheckBoxParams> _checkBoxes;
    std::vector<SpinBoxParams> _spinBoxes;
};

struct RadioButtonParams
{
    std::string _name;
};
struct ImageFieldParams
{
    std::string _name;
};