#define _CRT_SECURE_NO_WARNINGS
#include "json.hpp"
#include <fstream>
#include "../Topology/Topology.h"
#include "../Components/Resistor.h"
#include "../Components/nmos.h"
using json = nlohmann::json;
using std::ifstream;
class JSON {
private:
	Topology* _createTopology(json parser);
	vector<Component*> _createComponents(json componentsParser);
	Component* _createComponent(json componentParser);
	Component* _createResistor(json componentParser);
	Component* _createNMOS(json componentParser);
public:
	JSON();
	Topology* readTopology(string fileName);
	//void writeTopology(const Topology& topology, string fileName);	
};
