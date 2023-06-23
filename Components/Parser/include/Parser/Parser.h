#pragma once
#include <fstream>
#include <stack>

#include "Error.h"
#include <Params/Form.h>

class Parser
{
public:
    Parser();
    ~Parser();
    bool checkFile();
    bool parcing();

    Params::Form getResult() const;

    std::string getError() { return error.getError(); }

private:
    const std::string pathFile{"../CppUI.txt"};

    std::ifstream fin;

    int line{0};
    std::string activeString{""};
    std::string parcingString{""};
    std::string valueString{""};
    std::stack<std::string> scope;

    bool onlyScope = false;

    Error error;
    Params::Form form;

    bool createWidget();
    bool paramWidget();

    bool getWidget();
    bool getParam();
    bool getValue();
    bool checkParam();
    std::string checkUniqueNames();
};