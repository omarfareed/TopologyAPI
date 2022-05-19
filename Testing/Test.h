#include "../Components/Resistor.h"
#include "../Components/NMOS.h"
#include "UnitTest.h"
#include "../Topology/Topology.h"
#include "../JSON/JSON.h"
#include "../API/API.h"
#include <iostream>
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
	void testTopology(Topology* topology, string expectedID, vector<Component*> expectedComponents);
	void testTopology();
	void testAPIReadTopology(API *api, string fileName, Topology *expectedTopology);
	void testAPIWriteTopology(API *api, string topologyID,  bool expected);
	void testAPIQueryTopologies(API* api , vector<Topology *> expectedTopologies);
	void testAPIDeleteTopology(API* api , string topologyID , vector<Topology*> expectedTopologies);
	void testAPIQueryDevices(API* api , string topologyID , vector<Component*> expectedComponents);
	void testAPIQueryDevicesWithNetlistNode(API* api , string topologyID , string netlistId , vector<Component*> expectedComponents);
	void testAPI();
};