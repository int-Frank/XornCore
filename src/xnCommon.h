#ifndef XNCOMMON_H
#define XNCOMMON_H

#include <stdint.h>

//--------------------------------------------------------------------------------
// Helper functions
//--------------------------------------------------------------------------------

namespace xn
{
  enum class MouseInput
  {
    LeftButton,
    RightButton,
    MiddleButton,
    COUNT
  };

  int asprintf(char **ppBuf, char const *fmt, ...);
}

#endif