#include "pch.h"

using namespace std;

extern "C"
{
    void (*QObject_setObjectName)(QObject* pObj, QString* pName);

    extern void SortPatch_HookSetObjectName();

    void SortPatch_HandleSetObjectName(QObject* pObj, QString* pName)
    {
        string typeName = pObj->GetTypeName();
        if (typeName == "TChooserView" ||
            typeName == "tchooser_table_widget_t")
        {
            QTableView* pView = (QTableView*)pObj;
            wstring objectName = pName->str();
            if (objectName == L"Choose a structure for offset" ||
                objectName == L"Functions" ||
                objectName == L"Exports" ||
                objectName == L"Choose a name" ||
                objectName == L"Choose a enum name" ||
                objectName == L"Choose a structure name" ||
                objectName == L"Names")
            {
                pView->sortByColumn(0, 0);
            }
            else if (objectName == L"Local Types")
            {
                pView->sortByColumn(1, 0);
            }
            else if (objectName == L"Imports")
            {
                pView->sortByColumn(2, 0);
            }
        }
        else if (typeName == "SOStructsAndUnions")
        {
            QTreeView* pView = (QTreeView*)pObj;
            pView->setSortingEnabled(true);
            pView->sortByColumn(0, 0);
        }
    }
}

void SortPatch::Apply()
{
    QObject_setObjectName = (decltype(QObject_setObjectName))GetProcAddress(QModule::Core, "?setObjectName@QObject@QT@@QEAAXAEBVQString@2@@Z");

    DetourTransactionBegin();
    DetourAttach((void**)&QObject_setObjectName, SortPatch_HookSetObjectName);
    DetourTransactionCommit();
}
