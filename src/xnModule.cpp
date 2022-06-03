
#include "xnModule.h"
#include "xnLogger.h"

namespace xn
{
  Module::Module(ModuleInitData *pData)
    : m_pShow(nullptr)
    , m_pLogger(nullptr)
    , m_pMessageBus(nullptr)
    , m_pMemMngr(nullptr)
  {
    if (pData != nullptr)
    {
      m_pShow = pData->pShow;
      m_pLogger = pData->pLogger;
      m_pMessageBus = pData->pMsgBus;
      m_pMemMngr = pData->pMemMngr;
    }
  }

  Module::~Module()
  {
    *m_pShow = false;
  }

  void Module::SetLogger(Logger *pLogger)
  {
    m_pLogger = pLogger;
  }
}