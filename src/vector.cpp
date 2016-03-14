#include <iostream>

template <typename T>
Vector<T>::Vector(const int capacity) {
	mSize = 0;
	mCapacity = capacity;
	mVector = new T [mSize];
}

template <typename T>
Vector<T>::~Vector() {
	delete[] mVector;
}

template <typename T>
void Vector<T>::copy(const int& capacity) {
	mCapacity = capacity;
	T* tmp_vector = new T[mCapacity];
	for (int i = 0; i < mSize; ++i) {
		tmp_vector[i] = mVector[i];
	}

	delete[] mVector;
	mVector = tmp_vector;
}

template <typename T>
void Vector<T>::insert(const T& data) {
	if (mCapacity <= mSize) copy(mCapacity*2);
	
	mVector[mSize++] = data;
}

template <typename T>
void Vector<T>::checkBoundary(const int& i) const throw (std::out_of_range) {
	if (i >= mSize) {
		std::string msg = "Out of range 0 - " + std::to_string(mSize - 1);
		throw std::out_of_range(msg);
	}
}

template <typename T>
T Vector<T>::operator[](const int& i) const throw (std::out_of_range) {
	checkBoundary(i);
	return mVector[i];
}

template <typename T>
void Vector<T>::print() const {
	for (int i = 0; i < mSize; ++i) 
		std::cout << mVector[i] << " ";
	std::cout << " | Size: " << mSize << " | Capacity: " << mCapacity;
	std::cout << std::endl;
}

template <typename T>
void Vector<T>::slide(const int& i) {
	for (int j = i + 1; j < mSize; ++j) {
		mVector[j - 1] = mVector[j];
	}
	--mSize;
}

template <typename T>
T Vector<T>::remove(const int& i) throw(std::out_of_range) {
	checkBoundary(i);
	T data = mVector[i];
	slide(i);

	if (mSize <= mCapacity/4) copy(mCapacity/2);

	return data;
}
