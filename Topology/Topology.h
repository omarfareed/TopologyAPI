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
	Topology operator=(const Topology& other);
	bool operator==(const Topology& other);
	Topology(string id , vector<Component*> components);
	Component* getComponent(string id);
	void addComponent(Component* component);
	void setComponents(vector<Component*> components);
	void setID(string id);
	string getID();
	vector<Component*> getComponents();
	vector<Component*> getComponentsWithNetlistNode(string netlistNodeID);
	void printComponents();
	~Topology();
};