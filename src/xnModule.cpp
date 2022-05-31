
#include "xnModule.h"
#include "xnLogger.h"

namespace xn
{
  Module::Module(bool *pShow, Logger *pLogger)
    : m_pLogger(pLogger)
    , m_pShow(pShow)
  {

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