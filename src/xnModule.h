#ifndef XNMODULE_H
#define XNMODULE_H

#include <string>

#include "xnGeometry.h"
#include "xnCommon.h"
#include "xnUIContext.h"
#include "xnModuleInitData.h"
#include "xnFlagArray.h"

namespace xn
{
  class IRenderer;

  class Module
  {
  public:

    Module(ModuleInitData *);
    virtual ~Module();

    void SetLogger(Logger *);

    virtual bool SetGeometry(std::vector<PolygonLoop> const &) = 0;
    
    virtual void MouseDown(uint32_t modState, vec2 const &) {};
    virtual void MouseUp(uint32_t modState) {};
    virtual void MouseMove(uint32_t modState, vec2 const &) {};

    void DoFrame(UIContext *);
    virtual void Render(IRenderer *) {}

    bool HasFocus() const { return m_hasFocus; }
    bool IsOpen() const { return m_show; }

  protected:

    virtual void _DoFrame(UIContext *) = 0;
    virtual void NewFrame(); // Optional frame setup, eg to set window flags, window size etc...

    UIFlags m_windowFlags;
    Logger *m_pLogger;

  private:
    bool m_hasFocus;
    bool m_show;
    std::string m_name;
    uint32_t m_ID;
  };
}

#endif