#include "Application.h"

namespace
{
    ParamsMock::Window params{
        "Test Project",
        400, // height
        360, // width
        {
            // button
            {
                "Button_Calculate", // name
                "Calculate",        // text
                10,                 // x
                60,                 // y
                50,                 // height
                325,                // width
                true,               // doubleclickable
                true                // clickable
            },
        },
        {
            // static controls
            {
                "Label_X_Square", // name
                "x^2 + ",         // text
                65,               // x
                20,               // y
                25,               // height
                50                // width
            },
            {
                "Label_X", // name
                "x + ",    // text
                175,       // x
                20,        // y
                25,        // height
                50         // width
            },
            {
                "Label_Equal_Zero", // name
                " = 0",             // text
                285,                // x
                20,                 // y
                25,                 // height
                50                  // width
            },
            {
                "Label_Answer", // name
                "",             // text
                10,             // x
                155,            // y
                200,            // height
                325             // width
            },
        },
        {
            // line edits
            {
                "Coefficient_X_Squared", // name
                10,                      // x
                20,                      // y
                25,                      // height
                50                       // width
            },
            {
                "Coefficient_X", // name
                120,             // x
                20,              // y
                25,              // height
                50               // width
            },
            {
                "Coefficient_Free_Member", // name
                230,                       // x
                20,                        // y
                25,                        // height
                50                         // width
            },

        },
        {
            // check boxes
            {
                "CheckBox_Show_Discriminant",    // name
                "Show discriminant calculation", // text
                10,                              // x
                120,                             // y
                25,                              // height
                325,                             // width
                true                             // clickable
            },
        },
        {
            // spin boxes
        },
        {
            // radiobuttons
        }};
}

Application::Application()
    : BaseApplication()
{
    auto *button = _mainWindow.findWidgetByName<Button>("Button_Calculate");
    if (button)
        button->_click.connect([this]()
                               { this->calculate(); });
}