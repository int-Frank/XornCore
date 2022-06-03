#ifndef XNMODULEINITDATA_H
#define XNMODULEINITDATA_H

#include <stdint.h>
#include <string>

namespace xn
{
  class Logger;
  class MessageBus;
  class IMemoryManager;

  struct ModuleInitData
  {
    uint32_t ID;
    std::string name;
    Logger *pLogger;
    MessageBus *pMsgBus;
    IMemoryManager *pMemMngr;
  };
}

#endif