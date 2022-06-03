#ifndef XNMESSAGE_H
#define XNMESSAGE_H

#include <stdint.h>
#include <string>
#include <type_traits>

namespace xn
{
  enum class MessageType
  {
    InsertVertex,
    RemoveVertex,
    MoveVertex,
    TransformPolygon,
    RemovePolygon,
    AddPolygon,
    CLIENT_START = 0xFFFF // Client ID's can start here
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

    virtual uint32_t GetID() const = 0;
    virtual std::string ToString() const = 0;

  protected:
    uint32_t m_flags;
  };
}
#endif