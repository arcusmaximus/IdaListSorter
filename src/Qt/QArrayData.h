#pragma once

template<typename T>
struct QArrayData
{
    int Refcount;
    int Size;
    int Capacity;
    long long Offset;

    const T* GetData()
    {
        return (const T*)((BYTE*)this + Offset);
    }
};
