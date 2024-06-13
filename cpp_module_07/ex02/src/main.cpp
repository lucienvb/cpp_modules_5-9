#include "../include/Array.hpp"

void test_int_array() {

    std::cout << ">> TEST INT ARRAY <<" << std::endl;

    Array<int> int_array(5);
    std::cout << "size of int_array is: " << int_array.size() << std::endl;

    for (int i = 0; i < 5; i++) {
        int_array[i] = i;
    }

    for (int i = 0; i < 5; i++) {
        std::cout << "int_array[" << i << "]: " << int_array[i] << std::endl;
    }

    Array<int> copy_array = int_array;
    std::cout << "\ncopy_array on index 3 is: " << copy_array[3] << std::endl;
    std::cout << "int_array after copying on index 3 is: " << int_array[3] << std::endl;

    Array<int> assignment_array = copy_array;
    std::cout << "\nassignment_array on index 2 is: " << assignment_array[2] << std::endl;
    std::cout << "copy_array after assigning on index 2 is: " << copy_array[2] << std::endl;
}

void test_str_array() {

    std::cout << "\n>> TEST STR ARRAY <<" << std::endl;

    const Array<std::string> str_array(5);

    str_array[0] = "Hello";
    str_array[1] = "World";
    str_array[2] = "!";
    str_array[3] = ". . .";
    str_array[4] = "?!";

    for (int i = 0; i < 5; i++) {
        std::cout << "str_array[" << i << "]: " << str_array[i] << std::endl;
    }

    try {
        str_array[5] = "Out of bounds";
    }
    catch(std::exception &e)
    {
        std::cout << "Exception thrown: " << e.what() << std::endl;
    }
}

int main() {

    Array<int> empty_array;
    std::cout << "size of empty_array is: " << empty_array.size() << "\n" << std::endl;
    
    test_int_array();

    test_str_array();
}