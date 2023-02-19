#ifndef XNCOMMON_H
#define XNCOMMON_H

#include <stdint.h>

//--------------------------------------------------------------------------------
// Helper functions
//--------------------------------------------------------------------------------

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