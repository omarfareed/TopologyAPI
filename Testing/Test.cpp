#include "Test.h"

Component *Test::_createResistorTestCase(string id, string t1, string t2, double defaultVal, double minVal, double maxVal)
{
	map<string, string> netlist;
	netlist["t1"] = t1;
	netlist["t2"] = t2;
	map<string, double> info = this->_createInfo(defaultVal, minVal, maxVal);
	return new Resistor(id, netlist, info);
}

Component *Test::_createNMOSTestCase(string id, string drain, string source, string gate, double defaultVal, double minVal, double maxVal)
{
	map<string, string> netlist;
	netlist["drain"] = drain;
	netlist["gate"] = gate;
	netlist["source"] = source;
	map<string, double> info = this->_createInfo(defaultVal, minVal, maxVal);
	return new NMOS(id, netlist, info);
}

map<string, double> Test::_createInfo(double defaultVal, double minVal, double maxVal)
{
	map<string, double> info;
	info["default"] = defaultVal;
	info["min"] = minVal;
	info["max"] = maxVal;
	return info;
}

Test::Test()
{
}

void Test::testTopologyGetID(Topology *topology, string expectedID)
{
	tester.assertEqual<string>(expectedID, topology->getID());
}

void Test::testTopologyGetComponent(Topology *topology, vector<Component *> expectedComponents)
{
	for (auto component : expectedComponents)
	{
		tester.assertEqual<Component>(*component, *topology->getComponent(component->getID()));
	}
}

void Test::testTopologyGetComponents(Topology *topology, vector<Component *> expectedComponents)
{
	tester.assertEqual<Component>(expectedComponents, topology->getComponents());
}

void Test::testTopologyAddComponent(Topology *topology, Component *addedComponent)
{
	vector<Component *> componentsBeforAddition = topology->getComponents();
	int size = componentsBeforAddition.size();
	componentsBeforAddition.push_back(addedComponent);
	topology->addComponent(addedComponent);
	vector<Component *> componentsAfterAddition = topology->getComponents();
	tester.assertEqual<int>(size + 1, componentsAfterAddition.size());
	tester.assertEqual<vector<Component *>>(componentsBeforAddition, componentsAfterAddition);
	componentsBeforAddition.pop_back();
	topology->setComponents(componentsBeforAddition);
}

void Test::testTopologyGetComponentsWithNetlistNode(Topology *topology, string netlistId, vector<Component *> expectedComponents)
{
	vector<Component *> netlistComponent = topology->getComponentsWithNetlistNode(netlistId);
	tester.assertEqual<Component>(expectedComponents, netlistComponent);
}

void Test::testTopologySetComponents(Topology *topology, vector<Component *> components)
{
	vector<Component *> componentsBeforSet = topology->getComponents();
	topology->setComponents(components);
	tester.assertEqual<vector<Component *>>(components, topology->getComponents());
	topology->setComponents(componentsBeforSet);
}

void Test::testComponent()
{
	Component *comp1 = this->_createResistorTestCase("R1", "R2", "N1", 100, 80, 150);
	Resistor *R1 = (Resistor *)(comp1);
	tester.assertEqual<string>(comp1->getID(), "R1");
	tester.assertEqual<string>(R1->getT1(), "R2");
	tester.assertEqual<string>(R1->getT2(), "N1");
	tester.assertEqual<double>(R1->getDefaultValue(), 100);
	tester.assertEqual<double>(R1->getMinValue(), 80);
	tester.assertEqual<double>(R1->getMaxValue(), 150);
	Component *comp2 = this->_createNMOSTestCase("N1", "R1", "R2", "R3", 50, 15, 1000);
	NMOS *N1 = (NMOS *)(comp2);
	tester.assertEqual<string>(N1->getID(), "N1");
	tester.assertEqual<string>(N1->getDrain(), "R1");
	tester.assertEqual<string>(N1->getSource(), "R2");
	tester.assertEqual<bool>(N1->connectedTo(R1), true);
	tester.assertEqual<bool>(comp1->connectedTo(comp2), true);
	tester.assertEqual<bool>(*comp1 == *N1, false);
	tester.assertEqual<bool>(*comp1 == *R1, true);
}

void Test::testTopology(Topology *topology, string expectedID, vector<Component *> expectedComponents)
{
	tester.assertEqual<Topology>(*topology, *(new Topology(expectedID, expectedComponents)));
}
void Test::testTopology()
{
	Topology *t1 = parser.readTopology("./Testing/topology_test_case_1.json");
	tester.assertNotEqual<Topology *>(t1, NULL);
	if (t1 == NULL)
	{
		cout << "failed in reading topology" << endl;
		return;
	}
	this->testTopologyGetID(t1, "top1");
	Component *comp1 = this->_createResistorTestCase("res1", "vdd", "n1", 100, 10, 1000);
	Component *comp2 = this->_createNMOSTestCase("m1", "n1", "vss", "vin", 1.5, 1, 2);
	this->testTopologyGetComponent(t1, vector<Component *>{comp1, comp2});
	this->testTopologyGetComponents(t1, vector<Component *>{comp1, comp2});
	Component *comp3 = this->_createResistorTestCase("n1", "res1", "m1", 12, 10.5, 15);
	this->testTopologyAddComponent(t1, comp3);
	Component *comp4 = this->_createResistorTestCase("vdd", "res1", "vss", 10, 9, 20);
	this->testTopologyGetComponentsWithNetlistNode(t1, "res1", vector<Component *>{comp1});
	t1->addComponent(comp3);
	t1->addComponent(comp4);
	this->testTopologyGetComponentsWithNetlistNode(t1, "res1", vector<Component *>{comp1, comp3, comp4});
	this->testTopologySetComponents(t1, vector<Component *>{comp1, comp2});
}

void Test::testAPIReadTopology(API *api, string fileName, Topology *expectedTopology)
{
	Topology *topology = api->readTopology(fileName);
	cout << topology->getID() << endl;
	for (auto t : topology->getComponents())
	{
		cout << t->getID() << " ";
	}
	cout << endl;
	tester.assertEqual<Topology>(*topology, *expectedTopology);
}

void Test::testAPIWriteTopology(API *api, string topologyID, bool expectedHasWritten)
{
	bool hasWritten = api->writeTopology(topologyID);
	tester.assertEqual<bool>(hasWritten, expectedHasWritten);
}

void Test::testAPIQueryTopologies(API *api, vector<Topology *> expectedTopologies)
{
	tester.assertEqual<Topology>(api->queueryTopologies(), expectedTopologies);
}

void Test::testAPIDeleteTopology(API *api, string topologyID, vector<Topology *> expectedTopologies)
{
	api->deleteTopology(topologyID);
	tester.assertEqual<Topology>(api->queueryTopologies(), expectedTopologies);
}

void Test::testAPIQueryDevices(API *api, string topologyID, vector<Component *> expectedComponents)
{
	tester.assertEqual<Component>(api->queryDevices(topologyID), expectedComponents);
}

void Test::testAPIQueryDevicesWithNetlistNode(API *api, string topologyID, string netlistId, vector<Component *> expectedComponents)
{
	tester.assertEqual<Component>(api->queryDevicesWithNetlistNodes(topologyID, netlistId), expectedComponents);
}

void Test::testAPI()
{
	API *api = new API();
	Component *R1 = this->_createResistorTestCase("R1", "N1", "N2", 100, 50, 150);
	Component *R2 = this->_createResistorTestCase("R2", "N1", "N2", 100, 50, 150);
	Component *R3 = this->_createResistorTestCase("R3", "N1", "N2", 100, 50, 150);
	Component *N1 = this->_createNMOSTestCase("N1", "R1", "R3", "R2", 20, 15, 30);
	Component *N2 = this->_createNMOSTestCase("N2", "R1", "R3", "R2", 20, 15, 30);
	vector<Component *> components = vector<Component *>{R1, N1, R2, R3, N2};
	this->testAPIReadTopology(api, "./Testing/topology_test_1.json", new Topology("top_test1", components));
	this->testAPIWriteTopology(api, "top_test1", true);
	this->testAPIWriteTopology(api, "top_test2", false);
	this->testAPIQueryDevices(api, "top_test1", components);
	this->testAPIQueryDevicesWithNetlistNode(api, "top_test1", "R1", vector<Component*> {R1 , N1 , N2});
	this->testAPIQueryTopologies(api, vector<Topology*>{new Topology("top_test1", components)});
}
