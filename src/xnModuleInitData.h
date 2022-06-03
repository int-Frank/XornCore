#ifndef XNMODULEINITDATA_H
#define XNMODULEINITDATA_H

namespace xn
{
  class Logger;
  class MessageBus;
  class IMemoryManager;

  struct ModuleInitData
  {
    bool *pShow;
    Logger *pLogger;
    MessageBus *pMsgBus;
    IMemoryManager *pMemMngr;
  };
}

#endif