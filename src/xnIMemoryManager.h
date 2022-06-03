#ifndef XNIMEMORYMANAGER_H
#define XNIMEMORYMANAGER_H

#include <stdint.h>

namespace xn
{
  // Client memory manager for the MessageBus should be thread safe
  class IMemoryManager
  {
  public:

    virtual void *Malloc(size_t, bool zero = true) = 0;
    virtual void Free(void *) = 0;
    virtual void Memcpy(void *pDest, void *pSrc, size_t size) = 0;
  };
}

#endif