#ifndef XNCOMMON_H
#define XNCOMMON_H

#include <stdint.h>

#include "xnLogger.h"

//--------------------------------------------------------------------------------
// Helper functions
//--------------------------------------------------------------------------------

// Helpers for module loggin
#define M_LOG_DEBUG(...)   do{if (m_pLogger != nullptr) {char *__LOGMSGBUF = nullptr; ::xn::asprintf(&__LOGMSGBUF, __VA_ARGS__); m_pLogger->LogDebug(__LOGMSGBUF); delete[] __LOGMSGBUF;}} while(false)
#define M_LOG_INFO(...)    do{if (m_pLogger != nullptr) {char *__LOGMSGBUF = nullptr; ::xn::asprintf(&__LOGMSGBUF, __VA_ARGS__); m_pLogger->LogInfo(__LOGMSGBUF); delete[] __LOGMSGBUF;}} while(false)
#define M_LOG_WARNING(...) do{if (m_pLogger != nullptr) {char *__LOGMSGBUF = nullptr; ::xn::asprintf(&__LOGMSGBUF, __VA_ARGS__); m_pLogger->LogWarning(__LOGMSGBUF); delete[] __LOGMSGBUF;}} while(false)
#define M_LOG_ERROR(...)   do{if (m_pLogger != nullptr) {char *__LOGMSGBUF = nullptr; ::xn::asprintf(&__LOGMSGBUF, __VA_ARGS__); m_pLogger->LogError(__LOGMSGBUF); delete[] __LOGMSGBUF;}} while(false)

#define HAS_MOD_SHIFT(x) ((x & xn::MK_shift) != 0)
#define HAS_MOD_CTRL(x) ((x & xn::MK_ctrl) != 0)
#define HAS_MOD_ALT(x) ((x & xn::MK_alt) != 0)

namespace xn
{
  enum ModKey
  {
    MK_shift  = 1 << 0,
    MK_ctrl   = 1 << 1,
    MK_alt    = 1 << 2
  };

  int asprintf(char **ppBuf, char const *fmt, ...);
}

#endif