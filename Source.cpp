#include "Testing/Test.h"
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
	cout << "added topology with ID : " << topology1->getID() << endl;
	Topology* topology2 = api.readTopology("Testing/topology_test_1.json");
	cout << "added topology with ID : " << topology2->getID() << endl;
	if (!api.writeTopology(topology1->getID()))
	{
		cout << "Failed to write topology with id : " << topology1->getID() << endl;
	}
	else{
		cout << "topology has been written at file ./topologyWrite.json" << endl;
	}
	string top1Id = topology1->getID();
	if (api.deleteTopology(topology1->getID()))
		cout << "Deleted Topology with ID : " << top1Id << endl;
	else
		cout << "Failed To Delete Topology" << endl;
	vector<Component*> topolgyComponents = api.queryDevices(topology2->getID());
	cout << "Topology 2 components : " << endl;
	printComponents(topolgyComponents);
	vector<Component*> netlistComponents = api.queryDevicesWithNetlistNodes(topology2->getID(), "N1"); cout << "Netlist Components : " << endl;
	printComponents(netlistComponents);
	return 0;
}