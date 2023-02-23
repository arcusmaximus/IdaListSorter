#include "pch.h"

extern "C"
{
    void* Proxy_OriginalgluBeginCurve;
    void* Proxy_OriginalgluBeginPolygon;
    void* Proxy_OriginalgluBeginSurface;
    void* Proxy_OriginalgluBeginTrim;
    void* Proxy_OriginalgluBuild1DMipmaps;
    void* Proxy_OriginalgluBuild2DMipmaps;
    void* Proxy_OriginalgluCylinder;
    void* Proxy_OriginalgluDeleteNurbsRenderer;
    void* Proxy_OriginalgluDeleteQuadric;
    void* Proxy_OriginalgluDeleteTess;
    void* Proxy_OriginalgluDisk;
    void* Proxy_OriginalgluEndCurve;
    void* Proxy_OriginalgluEndPolygon;
    void* Proxy_OriginalgluEndSurface;
    void* Proxy_OriginalgluEndTrim;
    void* Proxy_OriginalgluErrorString;
    void* Proxy_OriginalgluErrorUnicodeStringEXT;
    void* Proxy_OriginalgluGetNurbsProperty;
    void* Proxy_OriginalgluGetString;
    void* Proxy_OriginalgluGetTessProperty;
    void* Proxy_OriginalgluLoadSamplingMatrices;
    void* Proxy_OriginalgluLookAt;
    void* Proxy_OriginalgluNewNurbsRenderer;
    void* Proxy_OriginalgluNewQuadric;
    void* Proxy_OriginalgluNewTess;
    void* Proxy_OriginalgluNextContour;
    void* Proxy_OriginalgluNurbsCallback;
    void* Proxy_OriginalgluNurbsCurve;
    void* Proxy_OriginalgluNurbsProperty;
    void* Proxy_OriginalgluNurbsSurface;
    void* Proxy_OriginalgluOrtho2D;
    void* Proxy_OriginalgluPartialDisk;
    void* Proxy_OriginalgluPerspective;
    void* Proxy_OriginalgluPickMatrix;
    void* Proxy_OriginalgluProject;
    void* Proxy_OriginalgluPwlCurve;
    void* Proxy_OriginalgluQuadricCallback;
    void* Proxy_OriginalgluQuadricDrawStyle;
    void* Proxy_OriginalgluQuadricNormals;
    void* Proxy_OriginalgluQuadricOrientation;
    void* Proxy_OriginalgluQuadricTexture;
    void* Proxy_OriginalgluScaleImage;
    void* Proxy_OriginalgluSphere;
    void* Proxy_OriginalgluTessBeginContour;
    void* Proxy_OriginalgluTessBeginPolygon;
    void* Proxy_OriginalgluTessCallback;
    void* Proxy_OriginalgluTessEndContour;
    void* Proxy_OriginalgluTessEndPolygon;
    void* Proxy_OriginalgluTessNormal;
    void* Proxy_OriginalgluTessProperty;
    void* Proxy_OriginalgluTessVertex;
    void* Proxy_OriginalgluUnProject;
};

void Proxy::Init(HMODULE hProxy)
{
    ProxyModuleHandle = hProxy;

    wchar_t path[MAX_PATH];
    GetSystemDirectory(path, MAX_PATH);
    wcscat_s(path, L"\\glu32.dll");
    OriginalModuleHandle = LoadLibrary(path);
    if (OriginalModuleHandle == nullptr)
    {
        MessageBox(nullptr, L"Cannot load original glu32 library", L"Proxy", MB_ICONERROR);
        ExitProcess(0);
    }

#define RESOLVE(fn) Proxy_Original##fn = reinterpret_cast<decltype(Proxy_Original##fn)>(GetProcAddress(OriginalModuleHandle, #fn))
    RESOLVE(gluBeginCurve);
    RESOLVE(gluBeginPolygon);
    RESOLVE(gluBeginSurface);
    RESOLVE(gluBeginTrim);
    RESOLVE(gluBuild1DMipmaps);
    RESOLVE(gluBuild2DMipmaps);
    RESOLVE(gluCylinder);
    RESOLVE(gluDeleteNurbsRenderer);
    RESOLVE(gluDeleteQuadric);
    RESOLVE(gluDeleteTess);
    RESOLVE(gluDisk);
    RESOLVE(gluEndCurve);
    RESOLVE(gluEndPolygon);
    RESOLVE(gluEndSurface);
    RESOLVE(gluEndTrim);
    RESOLVE(gluErrorString);
    RESOLVE(gluErrorUnicodeStringEXT);
    RESOLVE(gluGetNurbsProperty);
    RESOLVE(gluGetString);
    RESOLVE(gluGetTessProperty);
    RESOLVE(gluLoadSamplingMatrices);
    RESOLVE(gluLookAt);
    RESOLVE(gluNewNurbsRenderer);
    RESOLVE(gluNewQuadric);
    RESOLVE(gluNewTess);
    RESOLVE(gluNextContour);
    RESOLVE(gluNurbsCallback);
    RESOLVE(gluNurbsCurve);
    RESOLVE(gluNurbsProperty);
    RESOLVE(gluNurbsSurface);
    RESOLVE(gluOrtho2D);
    RESOLVE(gluPartialDisk);
    RESOLVE(gluPerspective);
    RESOLVE(gluPickMatrix);
    RESOLVE(gluProject);
    RESOLVE(gluPwlCurve);
    RESOLVE(gluQuadricCallback);
    RESOLVE(gluQuadricDrawStyle);
    RESOLVE(gluQuadricNormals);
    RESOLVE(gluQuadricOrientation);
    RESOLVE(gluQuadricTexture);
    RESOLVE(gluScaleImage);
    RESOLVE(gluSphere);
    RESOLVE(gluTessBeginContour);
    RESOLVE(gluTessBeginPolygon);
    RESOLVE(gluTessCallback);
    RESOLVE(gluTessEndContour);
    RESOLVE(gluTessEndPolygon);
    RESOLVE(gluTessNormal);
    RESOLVE(gluTessProperty);
    RESOLVE(gluTessVertex);
    RESOLVE(gluUnProject);
#undef RESOLVE
}
