#include "Application.h"

namespace
{
    Params::Window params{
        "Test Project",
        800,
        1200,
        {
            // button
            {
                "Button1",   // name
                "Calculate", // text
                10,          // x
                10,          // y
                50,          // height
                350,         // width
                true,        // doubleclickable
                true         // clickable
            },
            // {"Button2", "Button 2 (Only doubleclickable)", 25, 190, 50, 25},
            // {"Button3", "Button 3 (Multiply)", 25, 250, 50, 25},
            // {"Button4", "Button 4 (Noone event supported)", 25, 310, 50, 25},
        },
        {
            // static controls
            {
                "Label1",        // name
                "Random number", // text
                10,              // x
                130,             // y
                50,              // height
                350              // width
            },
            // {"Label2", "Button 2 clicked 0 times", 300, 190, 50, 400},
            // {"Label3", "Button 3 clicked 0 times", 300, 250, 50, 400},
            // {"Label4", "Button 4 clicked 0 times", 300, 310, 50, 400},
            // {"Label5", "Multiplier:", 25, 70, 50, 250},
            // {"Label6", "1", 300, 370, 50, 400},
            // {"Label7", "Copied multiplier:", 25, 370, 50, 250}
        },
        {
            // line edits
            {
                "Edit1", // name
                10,      // x
                300,     // y
                50,      // height
                250      // width
            },

        },
        {
            // check boxes
            {
                "CheckBox1", // name
                "CheckBox1", // text
                500,         // x
                300,         // y
                50,          // height
                150,         // width
                true         // clickable
            },
            // {"CheckBox2", "CheckBox2", 500, 500, 50, 150}
        },
        {
            // spin boxes
            {
                "SpinBox1", // name
                600,        // x
                50,         // y
                100,        // height
                200,        // width
                10,         // upper
                0,          // lower
                5           // default
            },
        },
        {
            // radiobuttons
            {"Radio Button1", // name
             250,             // x
             600,             // y
             30,              // height
             100,             // width
             "Option 1",      // text
             true, true},

            {"Radio Button2", // name
             250,             // x
             650,             // y
             30,              // height
             100,             // width
             "Option 2",      // text
             true, false},
            //{"Radio Button2", 250, 670, 30, 100, "Option 2", false, false},
            //{"Radio Button3", 400, 600, 30, 100, "Option 1", false, true},
            //{"Radio Button2", 400, 670, 30, 100, "Option 2", false, false},
        }};
}

Application::Application()
    : BaseApplication(params)
{
}