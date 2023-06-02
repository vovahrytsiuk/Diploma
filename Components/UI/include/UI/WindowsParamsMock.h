#pragma once

#include <vector>
#include <string>

namespace Params
{

    struct Button
    {
        std::string _name;
        std::string _text;
        int _x;
        int _y;
        int _height;
        int _width;
        bool _clickable;
        bool _doubleClickable;
    };

    struct Label
    {
        std::string _name;
        std::string _text;
        int _x;
        int _y;
        int _height;
        int _width;
    };

    struct FieldEdit
    {
        std::string _name;
        int _x;
        int _y;
        int _height;
        int _width;
    };

    struct CheckBox
    {
        std::string _name;
        std::string _text;
        int _x;
        int _y;
        int _height;
        int _width;
        bool _clickable;
    };

    struct SpinBox
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

    struct RadioButton
    {
        std::string _name;
        int _x;
        int _y;
        int _height;
        int _width;
        std::string _text;
        bool _clickable;
        bool _newGroup;
    };

    struct Window
    {
        std::string _title;
        int _height;
        int _width;
        std::vector<Params::Button> _buttons;
        std::vector<Params::Label> _labels;
        std::vector<Params::FieldEdit> _lineEdits;
        std::vector<Params::CheckBox> _checkBoxes;
        std::vector<Params::SpinBox> _spinBoxes;
        std::vector<Params::RadioButton> _radioButtons;
    };
}
