#include "pch.h"

using namespace std;

extern "C"
{
    void (*QObject_setObjectName)(QObject* pObj, QString& name);

    extern void SortPatch_HookSetObjectName();

    void SortPatch_HandleSetObjectName(QObject* pObj, QString& name)
    {
        const char* pTypeName = pObj->GetTypeName();
        if (strcmp(pTypeName, "TChooserView") == 0 ||
            strcmp(pTypeName, "tchooser_table_widget_t") == 0)
        {
            QTableView* pView = (QTableView*)pObj;
            if (name == L"Choose a structure for offset" ||
                name == L"Choose union representation" ||
                name == L"Functions" ||
                name == L"Exports" ||
                name == L"Choose a name" ||
                name == L"Choose a enum name" ||
                name == L"Choose a structure name" ||
                name == L"Names")
            {
                pView->sortByColumn(0, 0);
            }
            else if (name == L"Local Types")
            {
                pView->sortByColumn(1, 0);
            }
            else if (name == L"Imports")
            {
                pView->sortByColumn(2, 0);
            }
        }
        else if (strcmp(pTypeName, "SOStructsAndUnions") == 0)
        {
            QTreeView* pView = (QTreeView*)pObj;
            pView->setSortingEnabled(true);
            pView->sortByColumn(0, 0);
        }
    }
}

void SortPatch::Apply()
{
    if (QModule::Core == nullptr)
        return;

    QObject_setObjectName = (decltype(QObject_setObjectName))GetProcAddress(QModule::Core, "?setObjectName@QObject@QT@@QEAAXAEBVQString@2@@Z");
    if (QObject_setObjectName == nullptr)
        return;

    DetourTransactionBegin();
    DetourAttach((void**)&QObject_setObjectName, SortPatch_HookSetObjectName);
    DetourTransactionCommit();
}
