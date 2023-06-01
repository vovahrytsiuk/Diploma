#pragma once


#include <functional>
#include <vector>

class Event
{
public:
    using EventHandler = std::function<void()>;

    void connect(EventHandler eventHandler)
    {
        _handlers.push_back(eventHandler);
    }

    void emit()
    {
        for (const auto &eventHandler : _handlers)
        {
            eventHandler();
        }
    }

private:
    std::vector<EventHandler> _handlers;
};