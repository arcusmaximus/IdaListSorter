#pragma once

struct QMetaObject
{
    void* Super;
    QArrayData<char>* StringData;
};

class QObject
{
public:
    virtual QMetaObject* GetMetaObject() = 0;

    const char* GetTypeName()
    {
        QMetaObject* pMetadata = GetMetaObject();
        return pMetadata->StringData[0].GetData();
    }
};
