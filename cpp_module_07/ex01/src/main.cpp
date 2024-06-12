#include "../include/iter.hpp"

template <typename T> void    print(const T &instance) {
    std::cout << instance << std::endl;
}

template <typename T> void    increment(T &instance) {
   instance++;
}

int main() {

    char char_arr[] = {'a', 'b', 'c', 'd', 'e'};
    std::string str_arr[] = {"Hello", "world", "!", ". . ."};
    int int_arr[] = {42, 33, 17};
    float float_arr[] = {3.14, 42.42, 33.33333333, 0.0};

    std::cout << ">> char array <<" << std::endl;
    iter(char_arr, sizeof(char_arr)/sizeof(char_arr[0]), print<char>);
    std::cout << "\n>> string array <<" << std::endl;
    iter(str_arr, sizeof(str_arr)/sizeof(str_arr[0]), print<std::string>);
    std::cout << "\n>> int array <<" << std::endl;
    iter(int_arr, sizeof(int_arr)/sizeof(int_arr[0]), print<int>);
    std::cout << "\n>> float array <<" << std::endl;
    iter(float_arr, sizeof(float_arr)/sizeof(float_arr[0]), print<float>);

    std::cout << "\n>> int array <<" << std::endl;
    iter(int_arr, sizeof(int_arr)/sizeof(int_arr[0]), increment<int>);
    for (size_t i = 0; i < 3; i++) {
        std::cout << int_arr[i] << std::endl;
    }
    std::cout << "\n>> float array <<" << std::endl;
    iter(float_arr, sizeof(float_arr)/sizeof(float_arr[0]), increment<float>);
    for (size_t i = 0; i < 3; i++) {
        std::cout << float_arr[i] << std::endl;
    }

    return 0;
}
