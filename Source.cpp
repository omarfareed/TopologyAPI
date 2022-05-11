#define _CRT_SECURE_NO_WARNINGS
#include "JSON/JSON.h"
#include <iostream>
using json = nlohmann::json;
int main()
{
	(new JSON())->readTopology("topology.json");
}