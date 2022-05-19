#include "../Topology/Topology.h"
#include "../JSON/JSON.h"
class API
{
private:
	vector<Topology*> topologyList;
	JSON parser;
	Topology* _getTopology(string id);
public:
	Topology* readTopology(string fileName);
	bool writeTopology(string topologyID);
	vector<Topology*> queueryTopologies();
	bool deleteTopology(string topologyID);
	vector<Component*> queryDevices(string TopologyID);
	vector<Component*> queryDevicesWithNetlistNodes(string TopologyID, string netlistNodeID);
	void printAllTopologies();
};