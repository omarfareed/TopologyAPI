#include "API/API.h"
void printComponents(vector<Component*> components)
{
	for (auto component : components)
	{
		cout << component->getID() << " ";
	}
	cout << endl;
}
int main()
{
	API api;
	Topology* topology1 = api.readTopology("topology.json");
	Topology* topology2 = api.readTopology("Testing/topology_test_1.json");
	if (!api.writeTopology(topology1->getID()))
	{
		cout << "Failed to write topology with id : " << topology1->getID() << endl;
	}
	api.deleteTopology(topology1->getID());
	vector<Component*> topolgyComponents = api.queryDevices(topology2->getID());
	cout << "Topology 2 components : " << endl;
	printComponents(topolgyComponents);
	vector<Component*> netlistComponents = api.queryDevicesWithNetlistNodes(topology2->getID(), "N1");
	cout << "Netlist Components : " << endl;
	printComponents(netlistComponents);
	return 0;
}