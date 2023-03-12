#include <iostream>
#include <set>

void AddSet(std::set<int, std::greater<int>>& set) {
	std::cout << "Введите размер массива: ";
	int size;
	std::cin >> size;
	std::cout << "Заполните массив:" << std::endl;
	for (int i = 0; i < size; i++) {
		int temp;
		std::cout << i + 1 << ") - ";
		std::cin >> temp;
		set.emplace(temp);
	}
}

void PrintSet(std::set<int, std::greater<int>>& set) {
	std::cout << std::endl;
	std::cout << "[OUT]: " << std::endl;
	for (const auto& st : set) {
		std::cout << st << std::endl;
	}
}

int main(int argc, char** argv) {

	setlocale(LC_ALL, "rus");
	
	std::set <int, std::greater<int>> my_set;

	AddSet(my_set);

	PrintSet(my_set);

	return 0;
}