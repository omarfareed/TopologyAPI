#include "topologyTest.h"

topologyTest::topologyTest()
{
	this->fileName = fileName;
}

void topologyTest::test()
{
	Topology *t1 = parser.readTopology("./Testing/topology_test_case_1.json");
	if (t1 == NULL)
		return;
	tester.assertEqual<string>(t1->getID(), "top1");
	tester.assertEqual<int>(t1->getComponents().size(), 2);

}
