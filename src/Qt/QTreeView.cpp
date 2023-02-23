#include "pch.h"

void QTreeView::setSortingEnabled(bool enabled)
{
    static void (*QTreeView_setSortingEnabled)(QObject* pTree, bool enabled) =
        (decltype(QTreeView_setSortingEnabled))GetProcAddress(QModule::Widgets, "?setSortingEnabled@QTreeView@QT@@QEAAX_N@Z");
    QTreeView_setSortingEnabled(this, enabled);
}

void QTreeView::sortByColumn(int column, int order)
{
    static void (*QTreeView_sortByColumn)(QTreeView* pView, int column, int order) =
        (decltype(QTreeView_sortByColumn))GetProcAddress(QModule::Widgets, "?sortByColumn@QTreeView@QT@@QEAAXHW4SortOrder@Qt@2@@Z");
    QTreeView_sortByColumn(this, column, order);
}
