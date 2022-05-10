#define _CRT_SECURE_NO_WARNINGS
#include "JSON/json.hpp"
#include <iostream>
using json = nlohmann::json;
int main()
{
	auto j3 = json::parse(R"({"happy": true, "pi": 3.141 , "arr": [{"second" : "third"}]})");
	std::cout << j3.dump(4) << std::endl;
	return 0;

}