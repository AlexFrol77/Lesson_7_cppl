#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

void ConvertorMapVec(std::vector<std::pair<char, int>>& vec, std::map<char, int>& map) {
	for (auto st : map) {
		vec.push_back(st);
	}
}

bool Comp(std::pair<char, int>& a, std::pair<char, int>& b) {
	return a.second > b.second;
}

void PrintStringIn(const std::string& str) {
	std::cout << "[IN]: " << str << std::endl;
}

void PrintVecMapOut(const std::vector<std::pair<char, int>>& vec_map) {
	std::cout << "[OUT]: " << std::endl;
	for (const auto& st : vec_map) {
		std::cout << st.first << " : " << st.second << std::endl;
	}
}

int main(int argc, char** argv) {

	setlocale(LC_ALL, "rus");

	int count;
	std::map<char, int> my_map;
	std::vector <std::pair<char, int>> vec_map;
	std::string str_source =  "Hello world!!";

	for (int i = 0; i < str_source.size(); i++) {
		count = std::count(str_source.begin(), str_source.end(), str_source[i]);
		my_map.insert(std::make_pair(str_source[i], count));
	}
	
	ConvertorMapVec(vec_map, my_map);

	std::sort(vec_map.begin(), vec_map.end(), Comp);

	PrintStringIn(str_source);
	PrintVecMapOut(vec_map);

	return 0;
}