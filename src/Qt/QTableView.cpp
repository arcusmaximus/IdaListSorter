#include "pch.h"

void QTableView::sortByColumn(int column, int order)
{
    static void (*QTableView_sortByColumn)(QTableView* pView, int column, int order) =
        (decltype(QTableView_sortByColumn))GetProcAddress(QModule::Widgets, "?sortByColumn@QTableView@QT@@QEAAXHW4SortOrder@Qt@2@@Z");
    QTableView_sortByColumn(this, column, order);
}
