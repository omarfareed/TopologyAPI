#include "../JSON/JSON.h"
#include "UnitTest.h"
class topologyTest {
private:
	JSON parser;
	UnitTest tester;
	string fileName;
public:
	topologyTest();
	void test();
};