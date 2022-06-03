#ifndef XNPLUGINAPI_H
#define XNPLUGINAPI_H

#include <stdint.h>
#include <string>

#include "xnModuleInitData.h"

#define DLL_EXPORT extern "C" __declspec(dllexport)

typedef uint32_t(*xnPlugin_GetVersionFn)();
typedef xn::Module *(*xnPlugin_CreateModuleFn)(xn::ModuleInitData *);
typedef void (*xnPlugin_DestroyModuleFn)(xn::Module **);
typedef char const *(*xnPlugin_GetModuleNameFn)();

DLL_EXPORT uint32_t xnPlugin_GetVersion();
DLL_EXPORT void xnPlugin_DestroyModule(xn::Module **);
DLL_EXPORT xn::Module* xnPlugin_CreateModule(xn::ModuleInitData *);
DLL_EXPORT char const * xnPlugin_GetModuleName();

// Use this to define the following functions in your module:
// xnPlugin_GetVersion()
// xnPlugin_DestroyModule()
#define DEFINE_STANDARD_EXPORTS \
uint32_t xnPlugin_GetVersion(){return VERSION_AS_UINT;}\
void xnPlugin_DestroyModule(xn::Module **ppModule)\
{\
  if (ppModule != nullptr)\
  {\
    delete *ppModule;\
    *ppModule = nullptr;\
  }\
}

// Define the dll main function
#define DEFINE_DLLMAIN BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved){return TRUE;}

#endif