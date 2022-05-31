
#include <stdio.h>
#include <cstdlib>
#include <cstdarg>

#include "sstream"

#include "a2dCommon.h"
#include "a2dVersion.h"

namespace xn
{
  std::string VersionNumberToString(uint32_t version)
  {
    std::stringstream ss;
    ss << GET_VERSION_MAJOR(version) << '.' << GET_VERSION_MINOR(version) << '.' << GET_VERSION_PATCH(version);
    return ss.str();
  }

  int vasprintf(char **ppBuf, const char *fmt, va_list ap)
  {
    int len = _vscprintf(fmt, ap);
    if (len == -1)
      return -1;

    size_t size = (size_t)len + 1;
    char *pStr = (char*)malloc(size);
    if (!pStr)
      return -1;

    // _vsprintf_s is the "secure" version of vsprintf
    int r = vsprintf_s(pStr, len + 1, fmt, ap);
    if (r == -1) 
    {
      free(pStr);
      return -1;
    }
    *ppBuf = pStr;
    return r;
  }

  int asprintf(char **strp, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int r = vasprintf(strp, fmt, ap);
    va_end(ap);
    return r;
  }
}