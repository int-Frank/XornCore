#ifndef XNUICONTEXT_H
#define XNUICONTEXT_H

#include "DgVector.h"
#include "xnFlagArray.h"

namespace xn
{
  enum class UIFlag
  {
    IsActive
  };

  using UIFlags = FlagArray<UIFlag>;

  class UIContext
  {
  public:

    virtual ~UIContext() {}

    virtual void NewFrame() = 0;
    virtual void Compose() = 0;
    virtual void Draw() = 0;

    // Returns true if window has focus
    virtual bool BeginWindow(const char *name, bool *p_open = nullptr, UIFlags const *pFlags = nullptr) = 0;
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
    virtual bool InputText(const char *pLabel, char *pBuf, size_t bufSize) = 0;
    virtual bool Combo(const char *pLabel, int *pCurrentItem, const char *const pItems[], int itemCount, int displayItemsCount = -1) = 0;
    virtual bool RadioButton(const char *pLabel, int *pValue, int buttonHandle) = 0;
    virtual void SameLine() = 0;

    virtual bool SliderFloat(const char *label, float *v, float v_min, float v_max, const char *format = "%.3f", UIFlags const *pFlags = nullptr) = 0;
    virtual bool SliderInt(const char *label, int *v, int v_min, int v_max, const char *format = "%d", UIFlags const *pFlags = nullptr) = 0;
    virtual bool InputFloat(const char *label, float *v, float step, float step_fast, const char *format = "%.3f", UIFlags const *pFlags = nullptr) = 0;
  };
}

#endif