#include "Testing/componentTest.h"
#include "Testing/topologyTest.h"
//#include "API/API.h"
int main()
{
	/*
	API api;
	api.readJSON("topology.json");
	api.readJSON("topology2.json");
	api.writeJSON("top1");
	vector<Topology*> topologies = api.queueryTopologies();
	api.printAllTopologies();
	api.deleteTopology("top1");
	api.printAllTopologies();
	*/
	ComponentTest test1;
	test1.test();
	topologyTest test2;
	test2.test();
	return 0;
}