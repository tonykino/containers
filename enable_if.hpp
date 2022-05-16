#ifndef ENABLE_IF_TPP
#define ENABLE_IF_TPP

namespace ft {

template <bool, typename T = void>
struct enable_if
{};

template <typename T>
struct enable_if<true, T> {
  typedef T type;
};

}

#endif