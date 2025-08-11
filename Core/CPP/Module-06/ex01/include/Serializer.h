#ifndef SCHOOL_42_SERIALIZER_H
#define SCHOOL_42_SERIALIZER_H

#include "Data.h"

struct Data;

class Serializer {
	Serializer();
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &src);
	~Serializer();
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif