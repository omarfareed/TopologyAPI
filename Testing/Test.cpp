#include "Test.h"

Component* Test::_createResistorTestCase(string id, string t1, string t2, double defaultVal, double minVal, double maxVal)
{
	map<string, string> netlist;
	netlist["t1"] = t1;
	netlist["t2"] = t2;
	map<string, double> info = this->_createInfo(defaultVal, minVal, maxVal);
	return new Resistor(id, netlist, info);
}

Component* Test::_createNMOSTestCase(string id, string drain, string source, string gate, double defaultVal, double minVal, double maxVal)
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

void Test::testComponent()
{
	Component* comp1 = this->_createResistorTestCase("R1", "R2", "N1", 100, 80, 150);
	Resistor* R1 = (Resistor*)(comp1);
	tester.assertEqual<string>(comp1->getID(), "R1");
	tester.assertEqual<string>(R1->getT1(), "R2");
	tester.assertEqual<string>(R1->getT2(), "N1");
	tester.assertEqual<double>(R1->getDefaultValue(), 100);
	tester.assertEqual<double>(R1->getMinValue(), 80);
	tester.assertEqual<double>(R1->getMaxValue(), 150);
	Component* comp2 = this->_createNMOSTestCase("N1", "R1", "R2", "R3", 50, 15, 1000);
	NMOS* N1 = (NMOS*)(comp2);
	tester.assertEqual<string>(N1->getID(), "N1");
	tester.assertEqual<string>(N1->getDrain(), "R1");
	tester.assertEqual<string>(N1->getSource(), "R2");
	tester.assertEqual<bool>(N1->connectedTo(R1), true);
	tester.assertEqual<bool>(comp1->connectedTo(comp2), true);
	tester.assertEqual<bool>(*comp1 == *N1, false);
	tester.assertEqual<bool>(*comp1 == *R1, true);
}


void Test::testTopology()
{
	Topology *t1 = parser.readTopology("./Testing/topology_test_case_1.json");
	tester.assertNotEqual<Topology*>(t1, NULL);
	if (t1 == NULL) {
		cout << "failed in reading topology" << endl;
		return;
	}
	tester.assertEqual<string>(t1->getID(), "top1");
	tester.assertEqual<int>(t1->getComponents().size(), 2);
	Component* comp1 = this->_createResistorTestCase("res1", "vdd", "n1", 100, 10, 1000);
	Component* comp2 = this->_createNMOSTestCase( "m1", "n1", "vss", "vin", 1.5, 1, 2);;
	tester.assertEqual<Component>(*comp1, *t1->getComponent("res1"));
	tester.assertEqual<>(*t1->getComponents()[0], *comp1);
	tester.assertEqual<>(*t1->getComponents()[1], *comp2);
	Component* comp3 = this->_createResistorTestCase("n1", "res1", "m1", 12, 10.5, 15);
	Component* comp4 = this->_createResistorTestCase("vdd", "res1", "vss", 10, 9, 20);
	t1->addComponent(comp3);
	Component* comp = t1->getComponent("n1");
	cout << comp << endl;
	tester.assertEqual<>(comp3, t1->getComponent("n1"));
	tester.assertEqual<int>(t1->getComponents().size(), 3);
	cout << t1->getComponentsWithNetlistNode("res1").size();
	tester.assertEqual<int>(t1->getComponentsWithNetlistNode("res1").size(), 2);
	t1->addComponent(comp4);
	tester.assertEqual<int>(t1->getComponents().size(), 4);
	tester.assertEqual<int>(t1->getComponentsWithNetlistNode("res1").size(), 3);
	Component* R = t1->getComponent("res1");
	vector<Component*> elements;
	elements.push_back(R);
	elements.push_back(comp3);
	elements.push_back(comp4);
	tester.assertEqual<vector<Component*>>(elements, t1->getComponentsWithNetlistNode("res1"));
	Topology *t2 = parser.readTopology("./Testing/topology_test_case_1.json");
	Topology* t3 = parser.readTopology("./Testing/topology_test_case_1.json");
	tester.assertEqual<Topology>(*t3, *t2);
	tester.assertNotEqual<Topology*>(t3, t2);
	Topology t4 = *t3;
	tester.assertEqual<Topology>(t4, *t3);
}

