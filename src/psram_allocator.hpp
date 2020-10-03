#pragma once
#include <esp32-hal-psram.h>

#ifndef BOARD_HAS_PSRAM
#warning The selected board don't have PSRAM. The pstring will behave as regular std::string.
#endif

namespace Pstring {
template <class T> 
class psram_allocator {
public:
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef T *pointer;
  typedef const T *const_pointer;
  typedef T &reference;
  typedef const T &const_reference;
  typedef T value_type;

  psram_allocator() {}
  psram_allocator(const psram_allocator &) {}

  pointer allocate(size_type n, const void * = 0) {
    #ifdef BOARD_HAS_PSRAM
    T *t = (T *)ps_malloc(n * sizeof(T));
    #else
    T *t = (T *)malloc(n * sizeof(T));
    #endif
    return t;
  }

  void deallocate(void *p, size_type) {
    if (p) {
      free(p);
    }
  }

  pointer address(reference x) const { return &x; }
  const_pointer address(const_reference x) const { return &x; }
  psram_allocator<T> &operator=(const psram_allocator &) { return *this; }
  void construct(pointer p, const T &val) { new ((T *)p) T(val); }
  void destroy(pointer p) { p->~T(); }

  size_type max_size() const { return size_t(-1); }

  template <class U> struct rebind { typedef psram_allocator<U> other; };

  template <class U> psram_allocator(const psram_allocator<U> &) {}

  template <class U> psram_allocator &operator=(const psram_allocator<U> &) {
    return *this;
  }
};
}; // namespace pstring