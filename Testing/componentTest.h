#include "../Components/Resistor.h"
#include "../Components/NMOS.h"
#include "UnitTest.h"


class ComponentTest {
private:
	Component* _createResistorTestCase(string id, string t1, string t2, double defaultVal, double minVal, double maxVal);
	Component* _createNMOSTestCase(string id, string drain, string source, string gate, double defaultVal, double minVal, double maxVal);
	map<string, double> _createInfo(double defaultVal, double minVal, double MaxVal);
	UnitTest tester;
public:
	ComponentTest();
	void test();
};