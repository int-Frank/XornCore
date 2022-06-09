
#include "xnModule.h"
#include "xnLogger.h"
#include "xnMessageBus.h"
#include "xnXornMessages.h"

namespace xn
{
  Module::Module(ModuleInitData *pData)
    : m_hasFocus(false)
    , m_windowFlags()
    , m_name()
    , m_ID(0)
    , m_pLogger(nullptr)
    , m_pMessageBus(nullptr)
    , m_pMemMngr(nullptr)
  {
    if (pData != nullptr)
    {
      m_name = pData->name;
      m_ID = pData->ID;
      m_pLogger = pData->pLogger;
      m_pMessageBus = pData->pMsgBus;
      m_pMemMngr = pData->pMemMngr;
    }
  }

  Module::~Module()
  {

  }

  void Module::SetLogger(Logger *pLogger)
  {
    m_pLogger = pLogger;
  }

  void Module::DoFrame(UIContext *pContext, bool isActive)
  {
    NewFrame();
    bool show = true;
    m_windowFlags.SetFlag(UIFlag::IsActive, isActive);
    bool hasFocus = pContext->BeginWindow(m_name.c_str(), &show, &m_windowFlags);
    if (hasFocus != m_hasFocus && m_pMessageBus != nullptr)
    {
      if (hasFocus)
      {
        Message_ModuleGainedFocus * pMsg = m_pMessageBus->NewMessage<xn::Message_ModuleGainedFocus>();
        pMsg->windowID = m_ID;
        m_pMessageBus->Post(pMsg);
      }
      else
      {
        Message_ModuleLostFocus *pMsg = m_pMessageBus->NewMessage<xn::Message_ModuleLostFocus>();
        pMsg->windowID = m_ID;
        m_pMessageBus->Post(pMsg);
      }
      m_hasFocus = hasFocus;
    }

    _DoFrame(pContext);

    pContext->EndWindow();

    if (!show)
      Close();
  }

  void Module::Close()
  {
    if (m_pMessageBus != nullptr)
    {
      Message_ModuleClosed *pMsg = m_pMessageBus->NewMessage<xn::Message_ModuleClosed>();
      pMsg->windowID = m_ID;
      m_pMessageBus->Post(pMsg);
    }
  }

  void Module::NewFrame()
  {

  }
}