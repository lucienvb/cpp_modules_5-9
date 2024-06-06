#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;

    data.num = 42;
    data.c = '*';
    data.str = "Hello world!";
    data.f = 3.14;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "serialized data pointer: " << raw << std::endl;

    Data *deserialized_data = Serializer::deserialize(raw);
    std::cout << "deserialized data pointer: " << deserialized_data << std::endl;

    if (deserialized_data == &data) {
        std::cout << "num: " << deserialized_data->num << std::endl;
        std::cout << "char: " << deserialized_data->c << std::endl;
        std::cout << "str: " << deserialized_data->str << std::endl;
        std::cout << "float: " << deserialized_data->f << std::endl;
    }
    else
        std::cout << "deserialization failed" << std::endl;

    return 0;
}