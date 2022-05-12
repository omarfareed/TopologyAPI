#include "API/API.h"
int main()
{
	API api;
	api.readJSON("topology.json");
	api.readJSON("topology2.json");
	api.writeJSON("top1");
	vector<Topology*> topologies = api.queueryTopologies();
	api.printAllTopologies();
	api.deleteTopology("top1");
	api.printAllTopologies();
	return 0;
}