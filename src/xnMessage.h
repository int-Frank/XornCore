#ifndef XNMESSAGE_H
#define XNMESSAGE_H

#include <stdint.h>
#include <string>
#include <type_traits>

#include "Memory.h"

namespace xn
{
  class Message
  {
  public:

    enum class Flag : uint32_t
    {
      Handled = 1
    };

  public:

    Message();

    bool QueryFlag(Flag a_flag) const;
    void SetFlag(Flag a_flag, bool);
    uint32_t GetCategory() const;

    // All these defined in the macro (user do NOT implement)
    virtual uint32_t GetID() const = 0;

    // User defined
    virtual std::string ToString() const = 0;

  protected:
    uint32_t m_flags;
    static uint32_t GetNewID(uint32_t a_class);
  };
  
#define MESSAGE_HEADER \
  private:\
    static uint32_t s_ID;\
  public:\
    static uint32_t GetStaticID();\
    uint32_t GetID() const override;\
    size_t Size() const override;\
    std::string ToString() const override;

#define MESSAGE_DEFINITIONS(TYPE, CLASS) uint32_t TYPE::s_ID(0);\
  static_assert(std::is_trivially_destructible<TYPE>::value, #TYPE " must be trivially destructible");\
  uint32_t TYPE::GetStaticID()\
  {\
    if (s_ID == 0)\
      s_ID = GetNewID(CLASS);\
    return s_ID;\
  }\
  uint32_t TYPE::GetID() const\
  {\
    return GetStaticID();\
  }
}
#endif