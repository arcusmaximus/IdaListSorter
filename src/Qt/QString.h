#pragma once

class QString
{
public:
    std::wstring str()
    {
        return _data->AsWString();
    }

private:
    QArrayData* _data;
};
