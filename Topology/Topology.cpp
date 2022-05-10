#include "Topology.h"


Component* Topology::getComponent(string id)
{
	for (auto component : this->components)
	{
		if (component->getID() == id)
			return component;
	}
	return NULL;
}


Topology::Topology(string id)
{
	setID(id);
}

void Topology::addComponent(Component* component)
{
	this->components.push_back(component);
}

void Topology::setComponents(vector<Component*> components)
{
	this->components = components;
}

void Topology::setID(string id)
{
	if (id == "")
	{
		printf("invalid id \n");
		return;
	}
	this->id = id;
}

string Topology::getID()
{
	return this->id;
}

vector<Component*> Topology::getComponents()
{
	return this->components;
}

vector<Component*> Topology::getComponentsWithNetlistNode(string netlistNodeID)
{
	Component* netlistNode = getComponent(netlistNodeID);
	vector<Component*> netlist;
	netlist.push_back(netlistNode);
	for (auto component : this->components)
	{
		if (netlistNode->connectedTo(component))
			netlist.push_back(component);
	}
	return netlist;
}
