#pragma once

class QTreeView : public QObject
{
public:
    void setSortingEnabled(bool enabled);
    void sortByColumn(int column, int order);
};
