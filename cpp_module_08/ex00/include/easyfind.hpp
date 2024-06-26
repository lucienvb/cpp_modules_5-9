#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

class NotFoundException: public std::exception {
    public:
        virtual const char* what() const noexcept {
            return ("Target not found in container");
        }
};

template <typename T>
typename T::iterator easyfind(T& container, int target) {
    typename T::iterator it = std::find(container.begin(), container.end(), target);
    if (it == container.end())
        throw NotFoundException();
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int target) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), target);
    if (it == container.end())
        throw NotFoundException();
    return it;
}

#endif