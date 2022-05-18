#include "Testing/Test.h"
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
	Test test1;
	test1.testComponent();
	test1.testTopology();
	return 0;
}