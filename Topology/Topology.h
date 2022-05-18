#pragma once
#include "../Components/TwoTerminal.h"
#include "../Components/ThreeTerminal.h"
class Topology
{
private:
	string id;
	vector<Component* > components;
	void _deleteAllComponents();
public:
	Topology(const Topology& other);
	Topology(string id , vector<Component*> components);
	Topology operator=(const Topology& other);
	bool operator==(const Topology& other) const;
	Component* getComponent(string id) const;
	void addComponent(Component* component);
	void setComponents(vector<Component*> components);
	void setID(string id);
	string getID() const;
	vector<Component*> getComponents() const;
	vector<Component*> getComponentsWithNetlistNode(string netlistNodeID) const;
	void printComponents() const;
	~Topology();
};