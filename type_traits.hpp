#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft {

// enable_if
template <bool, typename T = void>
struct enable_if
{};

template <typename T>
struct enable_if<true, T> {
  typedef T type;
};

// integral_constant
template <class T, T v>
struct integral_constant {
	static const T value = v;
	typedef T value_type;
	typedef integral_constant<T,v> type;
	operator T() { return v; }
};

typedef integral_constant<bool, true>	true_type;
typedef integral_constant<bool, false>	false_type;

// is_integral
template<typename T>
struct is_integral: public false_type { };
	
template<>
struct is_integral<bool>: public true_type { };

template<>
struct is_integral<char>: public true_type { };

template<>
struct is_integral<signed char>: public true_type { };

template<>
struct is_integral<unsigned char>: public true_type { };

template<>
struct is_integral<wchar_t>: public true_type { };

template<>
struct is_integral<short>: public true_type { };

template<>
struct is_integral<unsigned short>: public true_type { };

template<>
struct is_integral<int>: public true_type { };

template<>
struct is_integral<unsigned int>: public true_type { };

template<>
struct is_integral<long>: public true_type { };

template<>
struct is_integral<unsigned long>: public true_type { };

template<>
struct is_integral<long long>: public true_type { };

template<>
struct is_integral<unsigned long long>: public true_type { };

}

#endif
