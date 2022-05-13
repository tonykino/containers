#include <vector>

namespace ft {
    template <class T, class Container = std::vector<T> >

    class stack {
    public:
        typedef Container container_type;
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;

        // Reference {from cppreference but not ISO/cplusplus} - useless?
        // Const reference {from cppreference but not ISO/cplusplus} - useless?

    protected:
        Container c;

    public:
        // constructor
        // destructor - use the default one {from cppreference} - useless
        // operator= - Use the default one {from cppreference} - useless

        explicit stack(const Container& cont = Container()) {};
        bool empty() const { return c.empty(); }
        size_type size() const { return c.size(); }
        value_type& top() { return c.back(); }
        const value_type& top() const { return c.back(); }
        void push(const value_type& x) { c.push_back(x); }
        void pop() { c.pop_back(); }
    };

    template <class T, class Container>
    bool operator==(const stack<T, Container>& x, const stack<T, Container>& y);

    template <class T, class Container>
    bool operator< (const stack<T, Container>& x, const stack<T, Container>& y);

    template <class T, class Container>
    bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y);

    template <class T, class Container>
    bool operator> (const stack<T, Container>& x, const stack<T, Container>& y);

    template <class T, class Container>
    bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y);

    template <class T, class Container>
    bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y);
}
