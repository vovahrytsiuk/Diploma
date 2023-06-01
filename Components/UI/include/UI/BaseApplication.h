#pragma once

#include "Window.h"
#include <string>
#include <CommCtrl.h>
#include "Widgets/Button.h"
#include "Widgets/Label.h"
#include "Widgets/CheckBox.h"
#include "WindowsParamsMock.h"
#include "Widgets/FieldEdit.h"
#include "Widgets/SpinBox.h"
#include "Widgets/RadioButton.h"

namespace
{

    // clang-format off
    WindowParams defaultParams{
        "Test Project",
        300,
        400,
        
        { // button
            {"Button1", "Click me!", 10, 10, 50, 350, true, true},
            // {"Button2", "Button 2 (Only doubleclickable)", 25, 190, 50, 25},
            // {"Button3", "Button 3 (Multiply)", 25, 250, 50, 25},
            // {"Button4", "Button 4 (Noone event supported)", 25, 310, 50, 25},
        },
        { // static controls
            {"Label1", "Random number", 10, 130, 50, 350},
            // {"Label2", "Button 2 clicked 0 times", 300, 190, 50, 400},
            // {"Label3", "Button 3 clicked 0 times", 300, 250, 50, 400},
            // {"Label4", "Button 4 clicked 0 times", 300, 310, 50, 400},
            // {"Label5", "Multiplier:", 25, 70, 50, 250},
            // {"Label6", "1", 300, 370, 50, 400},
            // {"Label7", "Copied multiplier:", 25, 370, 50, 250}
        },
        { // line edits
            //{"Edit1", 10, 300, 70, 50},
            
        },
        { // check boxes
            //{"CheckBox1", "CheckBox1", 500, 300, 50, 150, false},
            // {"CheckBox2", "CheckBox2", 500, 500, 50, 150}
        },
        { // spin boxes
            // std::string _name;
            // int _x;
            // int _y;
            // int _height;
            // int _width;
            // int _upper;
            // int _lower;
            // int _default;
            //{"SpinBox1", 600, 50, 100, 200, 10, 0, 5}
        },
        { // radiobuttons
            //{"Radio Button1", 250, 600, 30, 100, "Option 1", false, true},
            //{"Radio Button2", 250, 670, 30, 100, "Option 2", false, false},
            //{"Radio Button3", 400, 600, 30, 100, "Option 1", false, true},
            //{"Radio Button2", 400, 670, 30, 100, "Option 2", false, false},
        }
    };
    // clang-format on
}

class BaseApplication
{
public:
    BaseApplication(const WindowParams &params = defaultParams)
        : _hInstance{GetModuleHandle(NULL)}, _mainWindow{params._title, Size(params._height, params._width), _hInstance}

    {
        createMainWindowWidgets(params);
        // auto *button = _mainWindow.findWidgetByName<Button>("Button1");
        // button->_click.connect([]()
        //                        {MessageBox(NULL, "Clicked", "Clicked", MB_OK);; });

        _mainWindow.render();
    }

    void runMessageLoop()
    {
        MSG msg = {};
        while (GetMessage(&msg, NULL, 0, 0) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    Window &GetMainWindow()
    {
        return _mainWindow;
    }

private:
    template <class ParamsTypeT, typename CreatorFunc>
    void createWidgets(const std::vector<ParamsTypeT> &params, CreatorFunc creatorFunc)
    {
        for (const auto &param : params)
        {
            (this->*creatorFunc)(param);
        }
    }

    void createMainWindowWidgets(const WindowParams &params);
    void createButton(const ButtonParams &params);
    void createLabel(const LabelParams &params);
    void createFieldEdit(const FieldEditParams &params);
    void createSpinBox(const SpinBoxParams &params);
    void createRadioButton(const RadioButtonParams &params);
    void createCkeckBox(const CheckBoxParams &params);

protected:
    HINSTANCE _hInstance; // Application handle
    Window _mainWindow;   // Main window of the application
};