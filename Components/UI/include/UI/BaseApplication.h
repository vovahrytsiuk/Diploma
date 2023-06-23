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
#include <Params/Form.h>
class BaseApplication
{
public:
    BaseApplication(const ParamsMock::Window &params)
        : _hInstance{GetModuleHandle(NULL)}, _mainWindow{params._title, Size(params._height, params._width), _hInstance}

    {
        createMainWindowWidgets(params);
        _mainWindow.render();
    }

    BaseApplication();

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

    void createMainWindowWidgets(const ParamsMock::Window &params);
    void createButtonMock(const ParamsMock::Button &params);
    void createLabelMock(const ParamsMock::Label &params);
    void createFieldEditMock(const ParamsMock::FieldEdit &params);
    void createSpinBoxMock(const ParamsMock::SpinBox &params);
    void createRadioButtonMock(const ParamsMock::RadioButton &params);
    void createCkeckBoxMock(const ParamsMock::CheckBox &params);
    void createMainWindowWidgets(const Params::Form &params);
    void createButton(const Params::Button &params);
    void createLabel(const Params::Label &params);
    void createFieldEdit(const Params::EditLine &params);
    void createSpinBox(const Params::NumberBox &params);
    void createRadioButton(const Params::RadioButton &params);
    void createCkeckBox(const Params::CheckBox &params);

    void sortRadioButtonsByGroupNames(Params::Form &params);

protected:
    HINSTANCE _hInstance; // Application handle
    Window _mainWindow;   // Main window of the application
};