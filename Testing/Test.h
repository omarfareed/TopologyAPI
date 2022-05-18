#include "../Components/Resistor.h"
#include "../Components/NMOS.h"
#include "UnitTest.h"
#include "../Topology/Topology.h"
#include "../JSON/JSON.h"

class Test
{
private:
	Component *_createResistorTestCase(string id, string t1, string t2, double defaultVal, double minVal, double maxVal);
	Component *_createNMOSTestCase(string id, string drain, string source, string gate, double defaultVal, double minVal, double maxVal);
	map<string, double> _createInfo(double defaultVal, double minVal, double MaxVal);
	UnitTest tester;
	JSON parser;

public:
	Test();
	void testTopologyGetID(Topology *topology, string expectedID);
	void testTopologyGetComponent(Topology *topology, vector<Component *> expectedComponents);
	void testTopologyGetComponents(Topology *topology, vector<Component *> expectedComponents);
	void testTopologyAddComponent(Topology *topology, Component *addedComponent);
	void testTopologyGetComponentsWithNetlistNode(Topology *topology, string netlistId, vector<Component *> expectedComponents);
	void testTopologySetComponents(Topology *topology, vector<Component *> components);
	void testComponent();
	void testTopology();
};