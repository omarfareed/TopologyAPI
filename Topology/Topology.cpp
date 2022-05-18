#include "Topology.h"


void Topology::_deleteAllComponents()
{
	for (auto component : this->components)
		delete component;
}

Topology::Topology(const Topology& other)
{
	this->id = other.id;
	this->components = other.components;
}

Topology Topology::operator=(const Topology& other)
{
	if (this->components.size() != 0)
		this->_deleteAllComponents();
	this->components = other.components;
	this->id = other.id;
	return *this;
}

bool Topology::operator==(const Topology& other) const
{
	if (this->components.size() != other.components.size())
		return false;
	for (int i = 0; i < this->components.size(); i++)
	{
		if (!(*this->components[i] == *other.components[i]))
			return false;
	}
	return true;
}

Topology::Topology(string id, vector<Component*> components)
{
	setID(id);
	setComponents(components);
}

Component* Topology::getComponent(string id) const
{
	for (auto component : this->components)
	{
		cout << component->getID() << endl;
		if (component->getID() == id)
			return component;
	}
	return NULL;
}




void Topology::addComponent(Component* component)
{
	this->components.push_back(component);
	cout << "Component added : " << component->getID() << endl;
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

string Topology::getID() const
{
	return this->id;
}

vector<Component*> Topology::getComponents() const
{
	return this->components;
}

vector<Component*> Topology::getComponentsWithNetlistNode(string netlistNodeID) const
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

void Topology::printComponents() const
{
	for (auto component : this->components)
		component->printComponentInfo();
}

Topology::~Topology()
{
	this->_deleteAllComponents();
}
