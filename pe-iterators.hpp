#ifndef PE_ITERATORS
#define PE_ITERATORS
#include "pe-vector.hpp"

namespace knk
{
  template< class T >
  class VIter
  {
  public:
    VIter(Vector< T >&vec, size_t id) noexcept;

    T& operator*() const noexcept;
    T* operator->() const noexcept;
    T& operator[](size_t k) const noexcept;

    VIter& operator++() noexcept;
    VIter operator++(int) noexcept;
    VIter& operator--() noexcept;
    VIter operator--(int) noexcept;

    VIter& operator+=(int n) noexcept;
    VIter& operator-=(int n) noexcept;
    VIter operator+(int n) const noexcept;
    VIter operator-(int n) const noexcept;

    bool operator==(const VIter& other) const noexcept;
    bool operator!=(const VIter& other) const noexcept;
    bool operator<(const VIter& other) const noexcept;
    bool operator>(const VIter& other) const noexcept;
    bool operator<=(const VIter& other) const noexcept;
    bool operator>=(const VIter& other) const noexcept;

  private:
    T* ptr_;
  };
}

template< class T >
knk::VIter< T >::VIter(Vector< T >& vec, size_t id) noexcept:
  ptr_(&vec[id])
{
}

template< class T >
T& knk::VIter< T >::operator*() const noexcept
{
  return *ptr_;
}

template< class T >
T* knk::VIter< T >::operator->() const noexcept
{
  return ptr_;
}

template< class T >
T& knk::VIter< T >::operator[](size_t k) const noexcept
{
  return ptr_[k];
}

template< class T >
knk::VIter< T >& knk::VIter< T >::operator++() noexcept
{
  ++ptr_;
  return *this;
}

template< class T >
knk::VIter< T > knk::VIter< T >::operator++(int) noexcept
{
  VIter< T > tmp = *this;
  ++ptr_;
  return tmp;
}

template< class T >
knk::VIter< T >& knk::VIter< T >::operator--() noexcept
{
  --ptr_;
  return *this;
}

template< class T >
knk::VIter< T > knk::VIter< T >::operator--(int) noexcept
{
  VIter< T > tmp = *this;
  --ptr_;
  return tmp;
}

template< class T >
knk::VIter< T >& knk::VIter< T >::operator+=(int n) noexcept
{
  ptr_ += n;
  return *this;
}

template< class T >
knk::VIter< T >& knk::VIter< T >::operator-=(int n) noexcept
{
  ptr_ -= n;
  return *this;
}

template< class T >
knk::VIter< T > knk::VIter< T >::operator+(int n) const noexcept
{
  VIter< T > temp = *this;
  temp += n;
  return temp;
}

template< class T >
knk::VIter< T > knk::VIter< T >::operator-(int n) const noexcept
{
  VIter< T > temp = *this;
  temp -= n;
  return temp;
}

template< class T >
bool knk::VIter< T >::operator==(const VIter< T >& other) const noexcept
{
  return ptr_ == other.ptr_;
}

template< class T >
bool knk::VIter< T >::operator!=(const VIter< T >& other) const noexcept
{
  return ptr_ != other.ptr_;
}

template< class T >
bool knk::VIter< T >::operator<(const VIter< T >& other) const noexcept
{
  return ptr_ < other.ptr_;
}

template< class T >
bool knk::VIter< T >::operator>(const VIter< T >& other) const noexcept
{
  return ptr_ > other.ptr_;
}

template< class T >
bool knk::VIter< T >::operator<=(const VIter< T >& other) const noexcept
{
  return ptr_ <= other.ptr_;
}

template< class T >
bool knk::VIter< T >::operator>=(const VIter< T >& other) const noexcept
{
  return ptr_ >= other.ptr_;
}

#endif
