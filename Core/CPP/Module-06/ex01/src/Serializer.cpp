#include "../include/Serializer.h"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &src) {
	*this = src;
}

Serializer &Serializer::operator=(const Serializer &src) {
	if (&src == this)
		return *this;
	return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(const uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}