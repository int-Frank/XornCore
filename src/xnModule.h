#ifndef XNMODULE_H
#define XNMODULE_H

#include <string>

#include "xnGeometry.h"
#include "xnCommon.h"
#include "xnUIContext.h"
#include "xnModuleInitData.h"

// Helpers for module loggin
#define M_LOG_DEBUG(...)   do{if (m_pLogger != nullptr) {char *pMsg = nullptr; ::xn::asprintf(&pMsg, __VA_ARGS__); m_pLogger->LogDebug(pMsg); delete[] pMsg;}} while(false)
#define M_LOG_INFO(...)   do{if (m_pLogger != nullptr) {char *pMsg = nullptr; ::xn::asprintf(&pMsg, __VA_ARGS__); m_pLogger->LogInfo(pMsg); delete[] pMsg;}} while(false)
#define M_LOG_WARNING(...)   do{if (m_pLogger != nullptr) {char *pMsg = nullptr; ::xn::asprintf(&pMsg, __VA_ARGS__); m_pLogger->LogWarning(pMsg); delete[] pMsg;}} while(false)
#define M_LOG_ERROR(...)   do{if (m_pLogger != nullptr) {char *pMsg = nullptr; ::xn::asprintf(&pMsg, __VA_ARGS__); m_pLogger->LogError(pMsg); delete[] pMsg;}} while(false)

namespace xn
{
  class Renderer;

  class Module
  {
  public:

    Module(ModuleInitData *);
    virtual ~Module();

    void SetLogger(Logger *);

    // The first item in the geometry will be the boundary and will have a CCW winding.
    // Subsequent polygons will be holes and will have CW windings.
    // TODO this should be a PolygonWithHoles class
    virtual bool SetGeometry(PolygonGroup const &) = 0;
    virtual void Render(Renderer *pRenderer, mat33 const &T_World_View) = 0;

    void DoFrame(UIContext *);

  protected:

    void Close();

    virtual void _DoFrame(UIContext *) = 0;
    virtual void NewFrame(); // Optional frame setup, eg to set window flags, window size etc...

    uint32_t m_windowFlags;
    Logger *m_pLogger;
    IMemoryManager *m_pMemMngr;
    MessageBus *m_pMessageBus;

  private:
    bool m_hasFocus;
    std::string m_name;
    uint32_t m_ID;
  };
}

#endif