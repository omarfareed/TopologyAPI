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
	json _writeTopologyComponents(Topology*);
	json _writeTopologyComponent(Component*);
	json _getTopologyInfo(Component*);
public:
	JSON();
	JSON(const JSON& other);
	JSON operator=(const JSON&other);
	Topology* readTopology(string fileName);
	void writeTopology( Topology* topology, string fileName);	
};
