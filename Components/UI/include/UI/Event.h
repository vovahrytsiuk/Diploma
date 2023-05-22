#pragma once
#include <string>

class Event
{
    std::string _name;
};

enum Status
{
    Success,
    Waring,
    Error
};

struct OutPut
{
    Status _status;
    std::string _message; // empty if everything is ok
    WindowParams _params  /* widgets data data */
};
