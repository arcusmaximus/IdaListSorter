#pragma once

class QString
{
public:
    bool operator==(const wchar_t* psz) const
    {
        return wcscmp(_data->GetData(), psz) == 0;
    }

private:
    QArrayData<wchar_t>* _data;
};
