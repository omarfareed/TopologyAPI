#include "API.h"
Topology* API::_getTopology(string id)
{
	for (auto topology : this->topologyList)
		if (topology->getID() == id) return topology;
	return NULL;
}
Topology* API::readTopology(string fileName)
{
	Topology* topology = parser.readTopology(fileName);
	if (topology == NULL)
		return NULL;
	topologyList.push_back(topology);
	return topology;
}

bool API::writeTopology(string topologyID)
{
	Topology* topology = this->_getTopology(topologyID);
	if (topology == NULL)
		return false;
	parser.writeTopology(topology, "./topologyWrite.json");
	cout << "topology has been written at file ./topologyWrite.json" << endl;
	return true;
}

vector<Topology*> API::queueryTopologies()
{
	return this->topologyList;
}

bool API::deleteTopology(string topologyID)
{
	Topology* topology = _getTopology(topologyID);
	if (topology == NULL)
		return false;
	auto it = remove(this->topologyList.begin(), this->topologyList.end(), topology);
	topologyList.erase(it);
	delete topology;
	return true;
}

vector<Component*> API::queryDevices(string TopologyID)
{
	Topology* topology = _getTopology(TopologyID);
	if (topology == NULL)
		return vector<Component*>();
	return topology->getComponents();
}

vector<Component*> API::queryDevicesWithNetlistNodes(string TopologyID, string netlistNodeID)
{
	Topology* topology = _getTopology(TopologyID);
	if (topology == NULL)
		return vector<Component*>();
	return topology->getComponentsWithNetlistNode(netlistNodeID);
}
void API::printAllTopologies()
{
	for (auto topology : topologyList) 
	{
		cout << "ID : " << topology->getID() << endl;
		topology->printComponents();
	}
	cout << "FINISHED\n";
}
