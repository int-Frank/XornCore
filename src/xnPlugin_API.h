#ifndef A2DPLUGIN_API_H
#define A2DPLUGIN_API_H

#include <stdint.h>
#include <string>

namespace xn
{
  class Module;
  class Logger;
}

#define DLL_EXPORT extern "C" __declspec(dllexport)

typedef uint32_t(*a2dPlugin_GetVersionFn)();
typedef xn::Module *(*a2dPlugin_CreateModuleFn)(bool *pShow, xn::Logger *);
typedef void (*a2dPlugin_DestroyModuleFn)(xn::Module **);
typedef char const *(*a2dPlugin_GetModuleNameFn)();

DLL_EXPORT uint32_t a2dPlugin_GetVersion();
DLL_EXPORT void a2dPlugin_DestroyModule(xn::Module **);
DLL_EXPORT xn::Module* a2dPlugin_CreateModule(bool *pShow, xn::Logger *);
DLL_EXPORT char const * a2dPlugin_GetModuleName();

// Use this to define the following functions in your module:
// a2dPlugin_GetVersion()
// a2dPlugin_DestroyModule()
#define DEFINE_STANDARD_EXPORTS \
uint32_t a2dPlugin_GetVersion(){return VERSION_AS_UINT;}\
void a2dPlugin_DestroyModule(xn::Module **ppModule)\
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