#ifndef A2DUICONTEXT_H
#define A2DUICONTEXT_H

#include <stdint.h>

#include "DgVector.h"

namespace xn
{
  class UIContext
  {
  public:

    enum WindowFlags
    {

    };

    virtual ~UIContext() {}

    virtual void NewFrame() = 0;
    virtual void Compose() = 0;
    virtual void Draw() = 0;

    virtual bool BeginWindow(const char *name, bool *p_open = nullptr, uint32_t flags = 0) = 0;
    virtual void EndWindow() = 0;

    virtual Dg::Vector2<float> GetCursorPos() = 0;

    virtual void OpenPopup(const char *name, uint32_t flags = 0) = 0;
    virtual bool BeginPopup(const char *name, uint32_t flags = 0) = 0;
    virtual void EndPopup() = 0;
    virtual void PushTextWrapPos(float) = 0;
    virtual void PopTextWrapPos() = 0;

    virtual void Separator() = 0;
    virtual bool Button(const char *label, const Dg::Vector2<float> &size_arg = Dg::Vector2<float>(0.f, 0.f)) = 0;
    virtual void Text(const char *fmt, ...) = 0;
    virtual bool Checkbox(char const *pLabel, bool *pVal) = 0;

    virtual bool SliderFloat(const char *label, float *v, float v_min, float v_max, const char *format = "%.3f", uint32_t flags = 0) = 0;
    virtual bool SliderInt(const char *label, int *v, int v_min, int v_max, const char *format = "%d", uint32_t flags = 0) = 0;
  };
}

#endif