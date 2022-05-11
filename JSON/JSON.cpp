#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "JSON.h"

Component* JSON::_createComponent(json componentParser)
{
	string type = componentParser["type"];
	string id = componentParser["id"];
	if (type == "resistor")
		return _createResistor(componentParser);
	if (type == "nmos");
		return _createNMOS(componentParser);
	printf("unexpected component type\n");
	return NULL;
}
Component* JSON::_createResistor(json componentParser)
{
	map<string, string> netlist = componentParser["netlist"];
	map<string, double> info = componentParser["resistance"];
	string id = componentParser["id"];
	return new Resistor(id, netlist, info);
}
Component* JSON::_createNMOS(json componentParser)
{
	map<string, string> netlist = componentParser["netlist"];
	map<string, double> info = componentParser["m(l)"];
	string id = componentParser["id"];
	return new NMOS(id, netlist, info);
}
vector<Component*> JSON::_createComponents(json componentsParser)
{
	vector<Component*> components;
	for (auto componentParser : componentsParser)
		components.push_back(this->_createComponent(componentParser));	
	return components;
}
Topology* JSON::_createTopology(json parser)
{
	string id = parser["id"];
	vector<Component*> components = this->_createComponents(parser["components"]);
	return new Topology(id , components);
}
JSON::JSON()
{
}

Topology* JSON::readTopology(string fileName)
{
	try{
		if (fileName.find(".json") == string::npos)
			throw "invalid file name";
		FILE* file = fopen("./topology.json"  , "r");
		 json jsonParser = json::parse(file);
		if(jsonParser.empty()) return NULL;
		Topology* topology = this->_createTopology(jsonParser);
		topology->printComponents();
		return topology;
	}
	catch(string ex)
	{ 
		printf("there exist exception\n");
	}
}
