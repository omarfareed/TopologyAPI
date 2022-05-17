#include "../Components/Resistor.h"
#include "../Components/NMOS.h"
#include "UnitTest.h"


class ComponentTest : public UnitTest<Component>{
public:
	ComponentTest();
	bool isEqual(const Component& comp1 , const Component& comp2);
	void test();
};