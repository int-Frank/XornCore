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

    // Window
    WindowGainedFocus,
    WindowLostFocus,
    WindowClosed,

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

    virtual MessageType GetType() const = 0;
    virtual std::string ToString() const = 0;

  protected:
    uint32_t m_flags;
  };
}
#endif