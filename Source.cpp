#define _CRT_SECURE_NO_WARNINGS
#include "JSON/JSON.h"
#include <iostream>
using json = nlohmann::json;
int main()
{
	JSON js;
	Topology* topology = js.readTopology("toplogy.json");
	js.writeTopology(topology, "jsonTest.json");
}