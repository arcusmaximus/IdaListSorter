#pragma once

class QTableView : public QObject
{
public:
    void sortByColumn(int column, int order);
};
