#include "../Topology/Topology.h"
#include "../JSON/JSON.h"
class API
{
private:
	vector<Topology*> topologyList;
	JSON parser;
	Topology* _getTopology(string id);
public:
	bool readJSON(string fileName);
	bool writeJSON(string topologyID);
	vector<Topology*> queueryTopologies();
	bool deleteTopology(string topologyID);
	vector<Component*> queryDevices(string TopologyID);
	vector<Component*> queryDevicesWithNetlistNodes(string TopologyID, string netlistNodeID);
	void printAllTopologies();
};