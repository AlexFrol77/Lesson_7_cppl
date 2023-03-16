#pragma once

template <class T>
class MyVector {
public:
	MyVector();
	MyVector(int num);
	MyVector(const MyVector& other);
	MyVector& operator=(const MyVector& other);
	~MyVector();

	T& at(int index);
	T& operator[](int index);
	bool check_index();
	void push_back(T source);
	void operator=(T source);
	void add_memory(T source);
	int size();
	int capacity();
	void erase(int index);
	bool empty();
	T* begin();
	T* end();

private:
	T* ptr_vec;
	int _size,
		_count;
	T _source;


};