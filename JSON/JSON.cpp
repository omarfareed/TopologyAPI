#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "JSON.h"
#include <fstream>

Component* JSON::_createComponent(json componentParser)
{
	string type = componentParser["type"];
	string id = componentParser["id"];
	if (type == "resistor")
		return _createResistor(componentParser);
	if (type == "nmos")
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

JSON::JSON(const JSON& other)
{

}

JSON JSON::operator=(const JSON& other)
{
	return JSON();
}

Topology* JSON::readTopology(string fileName)
{
	try{
		if (fileName.find(".json") == string::npos)
			throw "invalid file name";
		std::ifstream file(fileName);
		json jsonParser = json::parse(file);
		if(jsonParser.empty()) return NULL;
		Topology* topology = this->_createTopology(jsonParser);
		topology->printComponents();
		return topology;
	}
	catch(string ex)
	{ 
		printf("there exist exception\n");
		return NULL;
	}
}

json JSON::_getTopologyInfo(Component* component)
{
	return { {"default" , component->getDefaultValue()} , {"min" , component->getMinValue() } , {"max" , component->getMaxValue()} };
}
json JSON::_writeTopologyComponent(Component* component)
{
	json JSONComponent;
	string id = component->getID();
	double defaultVal = component->getDefaultValue(), minVal = component->getMinValue(), maxVal = component->getMaxValue();
	JSONComponent = { {"id" , id }, {"netlist" , component->getNetlist()} ,{ "info" , this->_getTopologyInfo(component)} };
	return JSONComponent;
}
json JSON::_writeTopologyComponents(Topology* topology)
{
	vector<json> components;
	for (auto component : topology->getComponents())
		components.push_back(_writeTopologyComponent(component));
	return (json)components;
}
void JSON::writeTopology( Topology *topology, string fileName)
{
	json outJson;
	outJson = { {"id" , topology->getID()} ,{"components" , this->_writeTopologyComponents(topology)} };
	std::ofstream  file(fileName);
	file << outJson << endl;
	cout << "JSON file created\n";
}
