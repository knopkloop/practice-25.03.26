#ifndef PE_ITERATORS
#define PE_ITERATORS

#include <cstddef>

namespace knk
{
  template< class T >
  class Vector;

  template< class T >
  class VIter
  {
  public:
    VIter(Vector< T >&vec, size_t idx) noexcept;
    ~VIter() = default;

    T& operator*() const noexcept;

    VIter& operator++() noexcept;
    VIter operator++(int) noexcept;
    VIter& operator--() noexcept;
    VIter operator--(int) noexcept;

    VIter& operator+=(size_t n) noexcept;
    VIter& operator-=(size_t n) noexcept;
    VIter operator+(size_t n) const noexcept;
    VIter operator-(size_t n) const noexcept;

    bool operator==(const VIter& other) const noexcept;
    bool operator!=(const VIter& other) const noexcept;

  private:
    friend class Vector< T >;
    Vector< T >& vector_;
    size_t id_;
  };

  template< class T >
  class VCIter
  {
  public:
    VCIter(const Vector< T >&vec, size_t idx) noexcept;
    ~VCIter() = default;

    const T& operator*() const noexcept;

    VCIter& operator++() noexcept;
    VCIter operator++(int) noexcept;
    VCIter& operator--() noexcept;
    VCIter operator--(int) noexcept;

    VCIter& operator+=(size_t n) noexcept;
    VCIter& operator-=(size_t n) noexcept;
    VCIter operator+(size_t n) const noexcept;
    VCIter operator-(size_t n) const noexcept;

    bool operator==(const VCIter& other) const noexcept;
    bool operator!=(const VCIter& other) const noexcept;

  private:
    friend class Vector< T >;
    const Vector< T >& vector_;
    size_t id_;
  };
}

template< class T >
knk::VIter< T >::VIter(Vector< T >& vec, size_t idx) noexcept:
  vector_(vec),
  id_(idx)
{}

template< class T >
T& knk::VIter< T >::operator*() const noexcept
{
  return vector_[id_];
}

template< class T >
knk::VIter< T >& knk::VIter< T >::operator++() noexcept
{
  ++id_;
  return *this;
}

template< class T >
knk::VIter< T > knk::VIter< T >::operator++(int) noexcept
{
  VIter< T > tmp = *this;
  ++id_;
  return tmp;
}

template< class T >
knk::VIter< T >& knk::VIter< T >::operator--() noexcept
{
  --id_;
  return *this;
}

template< class T >
knk::VIter< T > knk::VIter< T >::operator--(int) noexcept
{
  VIter< T > tmp = *this;
  --id_;
  return tmp;
}

template< class T >
knk::VIter< T >& knk::VIter< T >::operator+=(size_t n) noexcept
{
  id_ += n;
  return *this;
}

template< class T >
knk::VIter< T >& knk::VIter< T >::operator-=(size_t n) noexcept
{
  id_ -= n;
  return *this;
}

template< class T >
knk::VIter< T > knk::VIter< T >::operator+(size_t n) const noexcept
{
  VIter< T > tmp = *this;
  tmp += n;
  return tmp;
}

template< class T >
knk::VIter< T > knk::VIter< T >::operator-(size_t n) const noexcept
{
  VIter< T > tmp = *this;
  tmp -= n;
  return tmp;
}

template< class T >
bool knk::VIter< T >::operator==(const VIter< T >& other) const noexcept
{
  return vector_ == other.vector_ && id_ == other.id_;
}

template< class T >
bool knk::VIter< T >::operator!=(const VIter< T >&other) const noexcept
{
  return !(*this == other);
}

template< class T >
knk::VCIter< T >::VCIter(const Vector< T >& vec, size_t idx) noexcept:
  vector_(vec),
  id_(idx)
{}

template< class T >
const T& knk::VCIter< T >::operator*() const noexcept
{
  return vector_[id_];
}

template< class T >
knk::VCIter< T >& knk::VCIter< T >::operator++() noexcept
{
  ++id_;
  return *this;
}

template< class T >
knk::VCIter< T > knk::VCIter< T >::operator++(int) noexcept
{
  VCIter< T > tmp = *this;
  ++id_;
  return tmp;
}

template< class T >
knk::VCIter< T >& knk::VCIter< T >::operator--() noexcept
{
  --id_;
  return *this;
}

template< class T >
knk::VCIter< T > knk::VCIter< T >::operator--(int) noexcept
{
  VCIter< T > tmp = *this;
  --id_;
  return tmp;
}

template< class T >
knk::VCIter< T >& knk::VCIter< T >::operator+=(size_t n) noexcept
{
  id_ += n;
  return *this;
}

template< class T >
knk::VCIter< T >& knk::VCIter< T >::operator-=(size_t n) noexcept
{
  id_ -= n;
  return *this;
}

template< class T >
knk::VCIter< T > knk::VCIter< T >::operator+(size_t n) const noexcept
{
  VCIter< T > tmp = *this;
  tmp += n;
  return tmp;
}

template< class T >
knk::VCIter< T > knk::VCIter< T >::operator-(size_t n) const noexcept
{
  VCIter< T > tmp = *this;
  tmp -= n;
  return tmp;
}

template< class T >
bool knk::VCIter< T >::operator==(const VCIter< T >& other) const noexcept
{
  return vector_ == other.vector_ && id_ == other.id_;
}

template< class T >
bool knk::VCIter< T >::operator!=(const VCIter< T >& other) const noexcept
{
  return !(*this == other);
}

#endif
