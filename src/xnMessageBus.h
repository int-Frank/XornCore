
#ifndef XNMESSAGEBUS_H
#define XNMESSAGEBUS_H

#include <type_traits>

#include "xnMessage.h"

namespace xn
{
  // Messages and message data should be created through an IMemoryManager given by the client.
  class MessageBus
  {
  public:

    MessageBus();
    ~MessageBus();

    void PostMessage(Message *);
    Message * PopMessage();

    // Messages must be created on the client side!
    template<typename T>
    T *NewMessage()
    {
      static_assert(std::is_base_of<Message, T>::value, "Type must be a subclass of Message!");
      return T::Create();
    }

  private:

    class PIMPL;
    PIMPL *m_pimpl;
  };
}

#endif