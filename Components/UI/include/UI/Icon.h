#pragma once

#include <Windows.h>

class Icon
{
public:
    Icon()
    {
        _handle = LoadIcon(NULL, IDI_APPLICATION);
    }
    Icon(const Icon &) = delete;
    Icon(Icon &&) = default;

    auto getHandle() const
    {
        return _handle;
    }
    ~Icon()
    {
        DestroyIcon(_handle);
    }

private:
    HICON _handle;
};