#ifndef XNFLAGS_H
#define XNFLAGS_H

#include <vector>

namespace xn
{
  template<typename T>
  class FlagArray
  {
  public:

    FlagArray();
    FlagArray(std::initializer_list<T> const &);

    void SetFlag(T const &, bool isOn);
    void ToggleFlag(T const &);
    bool QueryFlag(T const &) const;

  private:
    std::vector<bool> m_flagArray;
  };

  template<typename T>
  FlagArray<T>::FlagArray()
    : m_flagArray()
  {

  }

  template<typename T>
  FlagArray<T>::FlagArray(std::initializer_list<T> const &list)
  {
    for (T flag : list)
      SetFlag(flag, true);
  }

  template<typename T>
  void FlagArray<T>::SetFlag(T const &flag, bool isOn)
  {
    uint32_t index = (uint32_t)flag;
    if (index >= m_flagArray.size() && !isOn)
      return;

    if (index >= m_flagArray.size())
    {
      while (m_flagArray.size() <= index)
        m_flagArray.push_back(false);
    }

    m_flagArray[index] = isOn;
  }

  template<typename T>
  void FlagArray<T>::ToggleFlag(T const &flag)
  {
    bool isOn = QueryFlag(flag);
    SetFlag(flag, !isOn);
  }

  template<typename T>
  bool FlagArray<T>::QueryFlag(T const &flag) const
  {
    uint32_t index = (uint32_t)flag;
    if (index >= m_flagArray.size())
      return false;
    return m_flagArray[index];
  }
}

#endif