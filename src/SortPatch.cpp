#include "pch.h"

using namespace std;

extern "C"
{
    void (*QObject_setObjectName)(QObject* pObj, QString& name);
    void (*QDialog_showEvent)(QObject* pDialog, QObject* pEvent);

    QTableView* SortPatch_TableView;

    extern void SortPatch_HookSetObjectName();

    void SortPatch_HandleSetObjectName(QObject* pObj, QString& name)
    {
        const char* pTypeName = pObj->GetTypeName();
        if (strcmp(pTypeName, "TChooserView") == 0 ||
            strcmp(pTypeName, "tchooser_table_widget_t") == 0)
        {
            QTableView* pView = (QTableView*)pObj;
            if (name == L"Choose a structure for offset" ||
                name == L"Choose a structure (not the current!)" ||
                name == L"Choose a structure name" ||
                name == L"Select a structure:1" ||
                name == L"Choose union representation" ||
                name == L"Choose enum" ||
                name == L"Choose a enum name" ||
                name == L"Please choose enum" ||
                name == L"Choose a name" ||
                name == L"Choose a type")
            {
                SortPatch_TableView = pView;
            }
        }
        else if (strcmp(pTypeName, "SOStructsAndUnions") == 0)
        {
            QTreeView* pView = (QTreeView*)pObj;
            pView->setSortingEnabled(true);
            pView->sortByColumn(0, 0);
        }
    }

    extern void SortPatch_HookDialogShowEvent();

    void SortPatch_HandleDialogShowEvent(QObject* pDialog, QObject* pEvent)
    {
        if (SortPatch_TableView == nullptr)
            return;

        SortPatch_TableView->sortByColumn(0, 0);
        SortPatch_TableView = nullptr;
    }
}

void SortPatch::Apply()
{
    if (QModule::Core == nullptr)
        return;

    QObject_setObjectName = (decltype(QObject_setObjectName))GetProcAddress(QModule::Core, "?setObjectName@QObject@QT@@QEAAXAEBVQString@2@@Z");
    QDialog_showEvent = (decltype(QDialog_showEvent))GetProcAddress(QModule::Widgets, "?showEvent@QDialog@QT@@MEAAXPEAVQShowEvent@2@@Z");
    if (QObject_setObjectName == nullptr || QDialog_showEvent == nullptr)
        return;

    DetourTransactionBegin();
    DetourAttach((void**)&QObject_setObjectName, SortPatch_HookSetObjectName);
    DetourAttach((void**)&QDialog_showEvent, SortPatch_HookDialogShowEvent);
    DetourTransactionCommit();
}
