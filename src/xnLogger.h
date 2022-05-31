#ifndef A2DLOGGER_H
#define A2DLOGGER_H

namespace xn
{
  class Logger
  {
  public:

    virtual ~Logger() {}

    virtual bool Init() { return true; };
    virtual void Destroy() {};

    virtual void LogDebug(char const *) {};
    virtual void LogInfo(char const *) {};
    virtual void LogWarning(char const *) {};
    virtual void LogError(char const *) {};
  };
}

#endif