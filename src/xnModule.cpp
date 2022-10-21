
#include "xnModule.h"
#include "xnLogger.h"

namespace xn
{
  Module::Module(ModuleInitData *pData)
    : m_hasFocus(false)
    , m_show(true)
    , m_windowFlags()
    , m_name()
    , m_ID(0)
    , m_pLogger(nullptr)
  {
    if (pData != nullptr)
    {
      m_name = pData->name;
      m_ID = pData->ID;
      m_pLogger = pData->pLogger;
    }
  }

  Module::~Module()
  {

  }

  void Module::SetLogger(Logger *pLogger)
  {
    m_pLogger = pLogger;
  }

  void Module::DoFrame(UIContext *pContext)
  {
    NewFrame();
    m_hasFocus = pContext->BeginWindow(m_name.c_str(), &m_show, &m_windowFlags);
    _DoFrame(pContext);
    pContext->EndWindow();
  }

  void Module::NewFrame()
  {

  }
}