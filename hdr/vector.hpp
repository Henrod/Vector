#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdexcept>

template <typename T>
class Vector {
	public:
		Vector			(const int size = 1);
		virtual ~Vector		();
		void 	insert		(const T& data);
		T 	operator[]	(const int& i) const throw (std::out_of_range);
		T 	remove		(const int& i) throw(std::out_of_range);
		void 	print		() const;
	private:
		void 	checkBoundary	(const int& i) const throw (std::out_of_range);
		void 	slide		(const int& i);
		void 	copy		(const int& capacity);
		int 	mSize;
		int 	mCapacity;
		T* 	mVector;
};

#include "vector.cpp"

#endif //VECTOR_HPP
