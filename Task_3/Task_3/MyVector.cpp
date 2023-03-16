#include "MyVector.h"
#include <stdexcept>


template <class T>
MyVector<T>::MyVector() {
	this->_size = 1;
	this->_count = 0;
	this->ptr_vec = new T[_size];
}
template <class T>
MyVector<T>::MyVector(int num) {
	ptr_vec = new T[num];
	this->_size = num;
	this->_count = 0;
}
template <class T>
MyVector<T>::MyVector(const MyVector& other) {
	this->_size = other._size;
	this->ptr_vec = new T[other._size];
	for (int i = 0; i < other._count; i++) {
		this->ptr_vec[i] = other.ptr_vec[i];
		this->_count++;
	}
}
template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
	if (this == &other) {
		return *this;
	}
	else {
		this->_size = other._size;
		this->_count = other._count;
		delete[] this->ptr_vec;
		this->ptr_vec = new T[_size];
		for (int i = 0; i < _count; i++) {
			this->ptr_vec[i] = other.ptr_vec[i];
		}
	}
}
template <class T>
MyVector<T>::~MyVector() {
	delete[] ptr_vec;
	ptr_vec = nullptr;
}
template <class T>
bool MyVector<T>::check_index() {
	if (_count != 0) {
		return true;
	}
	else {
		throw std::runtime_error("Массив пустой");
	}
}
template <class T>
T& MyVector<T>::at(int index) {
	if (check_index()) {
		if (index >= 0 && index <= _count - 1) {
			return ptr_vec[index];
		}
		else {
			throw std::runtime_error("За границами массива");
		}
	}
}
template <class T>
T& MyVector<T>::operator[](int index) {
	if (check_index()) {
		if (index >= 0) {
			return ptr_vec[index];
		}
		else {
			throw std::runtime_error("За границами массива");
		}
	}
}
template <class T>
void MyVector<T>::add_memory(T source) {
		this->_size *= 2;
		T* ptr_temp = new T[_size];
		for (int i = 0; i < _size; i++) {
			ptr_temp[i] = ptr_vec[i];
		}
		delete[] ptr_vec;
		this->ptr_vec = ptr_temp;
		ptr_temp = nullptr;
		ptr_vec[_count++] = source;
}
template <class T>
void MyVector<T>::push_back(T source) {
	this->_source = source;
	if (_count < _size) {
		ptr_vec[_count++] = source;
	}
	else {
		add_memory(_source);
	}
}
template <class T>
void MyVector<T>::operator=(T source) {
	this->_source = source;
	if (_count < _size) {
		ptr_vec[_count++] = source;
	}
	else {
		add_memory(_source);
	}
}
template <class T>
int MyVector<T>::size() {
	return _count;
}
template <class T>
int MyVector<T>::capacity() {
	return _size;
}
template <class T>
void MyVector<T>::erase(int index) {
	if (_count > index) {
		for (int i = index; i < _count; i++) {
			this->ptr_vec[i] = this->ptr_vec[i + 1];
		}
		_count--;
	}
	else {
		throw std::runtime_error("Нет такого индекса");
	}
}
template <class T>
bool MyVector<T>::empty() {
	return _count;
}
template <class T>
T* MyVector<T>::begin() {
	return &ptr_vec[0];
}
template <class T>
T* MyVector<T>::end() {
	return &ptr_vec[_count];
}
