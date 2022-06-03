#include "xnMessage.h"
#include "xnXornMessages.h"

//-------------------------------------------------------------------
// Message
//-------------------------------------------------------------------

namespace xn
{
  Message::Message()
    : m_flags(0)
  {

  }

  bool Message::QueryFlag(Flag flag) const
  {
    return (m_flags & (uint32_t)flag) != 0;
  }

  void Message::SetFlag(Flag flag, bool on)
  {
    uint32_t u = (uint32_t)flag;
    if (on)
      m_flags = (m_flags & ~u);
    else
      m_flags = (m_flags | u);
  }

  //-------------------------------------------------------------------
  // Engine Messages
  //-------------------------------------------------------------------

#define MESSAGE_DEFINITION(t) uint32_t Message_ ## t::GetStaticID() {return (uint32_t)MessageType::t;}\
size_t Message_ ## t::Size() {return sizeof(Message_ ## t);}\
uint32_t Message_ ## t::GetID() const {return GetStaticID();}\
std::string Message_ ## t::ToString() const {return std::string(#t);}\
Message * Message_ ## t::Create() {return new Message_ ## t();}

  MESSAGE_DEFINITION(InsertVertex)
  MESSAGE_DEFINITION(RemoveVertex)
  MESSAGE_DEFINITION(MoveVertex)
  MESSAGE_DEFINITION(TransformPolygon)
  MESSAGE_DEFINITION(RemovePolygon)
  MESSAGE_DEFINITION(AddPolygon)

}