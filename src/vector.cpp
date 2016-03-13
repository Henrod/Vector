#include "vector.hpp"
#include <iostream>

Vector::Vector(const int capacity) {
	mSize = 0;
	mCapacity = capacity;
	mVector = new int [mSize];
}

Vector::~Vector() {
	delete[] mVector;
}

void Vector::copy(const int& capacity) {
	mCapacity = capacity;
	int* tmp_vector = new int[mCapacity];
	for (int i = 0; i < mSize; ++i) {
		tmp_vector[i] = mVector[i];
	}

	delete[] mVector;
	mVector = tmp_vector;
}

void Vector::insert(const int& data) {
	if (mCapacity <= mSize) copy(mCapacity*2);
	
	mVector[mSize++] = data;
}

void Vector::checkBoundary(const int& i) const throw (std::out_of_range) {
	if (i >= mSize) {
		std::string msg = "Out of range 0 - " + std::to_string(mSize - 1);
		throw std::out_of_range(msg);
	}
}

int Vector::operator[](const int& i) const throw (std::out_of_range) {
	checkBoundary(i);
	return mVector[i];
}

void Vector::print() const {
	for (int i = 0; i < mSize; ++i) 
		std::cout << mVector[i] << " ";
	std::cout << " | Size: " << mSize << " | Capacity: " << mCapacity;
	std::cout << std::endl;
}

void Vector::slide(const int& i) {
	for (int j = i + 1; j < mSize; ++j) {
		mVector[j - 1] = mVector[j];
	}
	--mSize;
}

int Vector::remove(const int& i) throw(std::out_of_range) {
	checkBoundary(i);
	int data = mVector[i];
	slide(i);

	if (mSize <= mCapacity/4) copy(mCapacity/2);

	return data;
}
