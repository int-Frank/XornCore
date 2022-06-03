
#include "xnModule.h"
#include "xnLogger.h"
#include "xnMessageBus.h"
#include "xnXornMessages.h"

namespace xn
{
  Module::Module(ModuleInitData *pData)
    : m_hasFocus(false)
    , m_windowFlags(0)
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

  void Module::DoFrame(UIContext *pContext)
  {
    NewFrame();
    bool show = true;
    bool hasFocus = pContext->BeginWindow(m_name.c_str(), &show, m_windowFlags);
    if (hasFocus != m_hasFocus && m_pMessageBus != nullptr)
    {
      if (hasFocus)
      {
        Message_WindowGainedFocus * pMsg = m_pMessageBus->NewMessage<xn::Message_WindowGainedFocus>();
        pMsg->windowID = m_ID;
        m_pMessageBus->PostMessage(pMsg);
      }
      else
      {
        Message_WindowLostFocus *pMsg = m_pMessageBus->NewMessage<xn::Message_WindowLostFocus>();
        pMsg->windowID = m_ID;
        m_pMessageBus->PostMessage(pMsg);
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
      Message_WindowClosed *pMsg = m_pMessageBus->NewMessage<xn::Message_WindowClosed>();
      pMsg->windowID = m_ID;
      m_pMessageBus->PostMessage(pMsg);
    }
  }

  void Module::NewFrame()
  {

  }
}