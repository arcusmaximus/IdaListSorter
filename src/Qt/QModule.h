#pragma once

class QModule
{
public:
    static inline HMODULE Core = GetModuleHandle(L"Qt5Core");
    static inline HMODULE Widgets = GetModuleHandle(L"Qt5Widgets");
};
