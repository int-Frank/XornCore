#ifndef XNMESSAGE_H
#define XNMESSAGE_H

#include <stdint.h>
#include <string>
#include <type_traits>

namespace xn
{
  enum class MessageType
  {
    // Editing geometry
    InsertVertex,
    RemoveVertex,
    MoveVertex,
    TransformPolygon,
    RemovePolygon,
    AddPolygon,

    // IO
    MouseDown,
    MouseUp,
    MouseMove,

    // Module
    ModuleGainedFocus,
    ModuleLostFocus,
    ModuleClosed,

    // End
    XORN_END = 0xFFFF // Custom ID's can start here
  };

  class Message
  {
  public:

    enum class Flag : uint32_t
    {
      Handled = 1 << 0
    };

  public:

    Message();

    bool QueryFlag(Flag flag) const;
    void SetFlag(Flag flag, bool);

    virtual uint32_t GetType() const = 0;
    virtual std::string ToString() const = 0;

  protected:
    uint32_t m_flags;
  };

#define MESSAGE_HEADER(t) \
  class Message_ ## t : public ::xn::Message {\
  public:\
    static size_t Size();\
    static uint32_t GetStaticType();\
    uint32_t GetType() const override;\
    std::string ToString() const override;\
    static Message_ ## t * Create();
}
#endif