#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>

struct Data {
    int     	num;
    char    	c;
    std::string	str;
	float		f;
};

class Serializer {
public:
	Serializer() = delete;
	Serializer(const Serializer &other) = delete;
	void operator=(const Serializer &other) = delete;
	~Serializer() = delete;

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif