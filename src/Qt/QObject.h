#pragma once

struct QMetaObject
{
    void* Super;
    QArrayData* StringData;
};

class QObject
{
public:
    virtual QMetaObject* GetMetaObject() = 0;

    std::string GetTypeName()
    {
        QMetaObject* pMetadata = GetMetaObject();
        return pMetadata->StringData[0].AsString();
    }
};
