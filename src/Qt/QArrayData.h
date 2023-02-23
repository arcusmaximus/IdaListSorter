#pragma once

struct QArrayData
{
    int Refcount;
    int Size;
    int Capacity;
    long long Offset;

    template<typename T>
    const T* GetData()
    {
        return (const T*)((BYTE*)this + Offset);
    }

    std::string AsString()
    {
        return std::string(GetData<char>(), Size);
    }

    std::wstring AsWString()
    {
        return std::wstring(GetData<wchar_t>(), Size);
    }
};
