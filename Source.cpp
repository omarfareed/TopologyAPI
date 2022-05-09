#define _CRT_SECURE_NO_WARNINGS
#include "json.hpp"
#include <iostream>
using json = nlohmann::json;
int main()
{
	FILE* file;
	file = fopen("file.json", "w");
	auto j3 = json::parse(file);
	j3["first"] = "second";
	std::cout << j3.dump(4) << std::endl;
	return 0;
	// look at asaad code
}