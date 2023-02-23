#pragma once

class Proxy
{
public:
    static void Init(HMODULE hProxy);

private:
    static inline HMODULE ProxyModuleHandle{};
    static inline HMODULE OriginalModuleHandle{};
};
