.code

extern QObject_setObjectName : dq

extern SortPatch_HandleSetObjectName : proc

SortPatch_HookSetObjectName proc
    push rcx
    push rdx
    sub rsp, 28h
    call SortPatch_HandleSetObjectName
    add rsp, 28h
    pop rdx
    pop rcx
    jmp [QObject_setObjectName]
SortPatch_HookSetObjectName endp

end
