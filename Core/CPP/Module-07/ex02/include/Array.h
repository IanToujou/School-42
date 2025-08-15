#ifndef ARRAY_H
#define ARRAY_H

#if __cplusplus >= 201703L
	#define NODISCARD [[nodiscard]]
#elif defined(__GNUC__) || defined(__clang__)
	#define NODISCARD __attribute__((warn_unused_result))
#elif defined(_MSC_VER)
	#define NODISCARD _Check_return_
#else
	#define NODISCARD
#endif

#include <cstddef>
#include <exception>

template <typename T>

class Array {
private:
	T *array;
	unsigned int size;
public:
	Array(): array(new T[0]), size(0) {};
	explicit Array(const unsigned int size): array(new T[size]), size(size) {};
	Array(const Array &src): size(src.size) {
		this->array = NULL;
		*this = src;
	};
	Array &operator=(const Array &src) {
		if (this == &src) return (*this);
		if (this->array != NULL) delete[] this->array;
		if (src.size != 0) {
			this->size = src.size;
			this->array = new T[this->size];
			for (unsigned int i = 0; i < this->size; i++)
				this->array[i] = src.array[i];
		}
		return (*this);
	};
	T& operator[](unsigned int index) {
		if (index >= this->size) throw ArrayIndexOutOfBoundsException();
		return this->array[index];
	}
	const T& operator[](unsigned int index) const {
		if (index >= this->size) throw ArrayIndexOutOfBoundsException();
		return this->array[index];
	}
	~Array() {
		if (this->array != NULL) delete[] this->array;
	};
	NODISCARD unsigned int getSize() const {
		return this->size;
	}
	class ArrayIndexOutOfBoundsException : public std::exception {
	public:
		NODISCARD virtual const char *what() const throw() {
			return "ArrayIndexOutOfBoundsException: Array index is out of bounds.";
		};
	};
};

#endif