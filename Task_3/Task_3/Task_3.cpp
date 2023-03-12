﻿#include <iostream>
#include <Windows.h>
#include <algorithm>
#include "MyVector.h"
#include "MyVector.cpp"

template <class T>
void Print(MyVector<T>& vec) {
	for (const auto& st : vec) {
		std::cout << st << " ";
	}
	std::cout << std::endl;
}


int main(int argc, char** argv) {

	setlocale(LC_ALL, "rus");

	MyVector<int> vec(1);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(7);
	vec.push_back(5);
	vec.push_back(2);
	vec[5] = 77;
	int temp = vec[1];
	vec.at(1) = 555;

	MyVector<int> vec2(vec);
	MyVector<int> vec3 = vec;
	MyVector<int> vec4;

	vec4 = vec;

	Print(vec);
	Print(vec2);
	Print(vec3);

	std::sort(vec.begin(), vec.end());
	vec2.erase(2);
	vec3 = vec;

	std::cout << "/////////////////" << std::endl;

	Print(vec);
	Print(vec2);
	Print(vec3);
	std::cout << "size vec: " << vec.size() << " capaity vec: " << vec.capacity() << std::endl;
	std::cout << "size vec 2: " << vec2.size() << " capaity vec 2: " << vec2.capacity() << std::endl;

	auto* it = vec4.begin();
	for (int i = 0; i < vec4.size(); i++) {
		std::cout << *it++ << " ";
	}
	std::cout << std::endl;

	return 0;
}