#include "componentTest.h"

Component* ComponentTest::_createResistorTestCase(string id, string t1, string t2, double defaultVal, double minVal, double maxVal)
{
	map<string, string> netlist;
	netlist["t1"] = t1;
	netlist["t2"] = t2;
	map<string, double> info = this->_createInfo(defaultVal, minVal, maxVal);
	return new Resistor("R1", netlist, info);
}

Component* ComponentTest::_createNMOSTestCase(string id, string drain, string source, string gate, double defaultVal, double minVal, double maxVal)
{
	map<string, string> netlist;
	netlist["drain"] = drain;
	netlist["gate"] = gate;
	netlist["source"] = source;
	map<string, double> info = this->_createInfo(defaultVal, minVal, maxVal);
	return new NMOS(id, netlist, info);
}

map<string, double> ComponentTest::_createInfo(double defaultVal, double minVal, double maxVal)
{
	map<string, double> info;
	info["default"] = defaultVal;
	info["min"] = minVal;
	info["max"] = maxVal;
	return info;
}

ComponentTest::ComponentTest()
{
}

void ComponentTest::test()
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
