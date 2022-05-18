#include "ThreeTerminal.h"

bool ThreeTerminal::validNetlist( map<string, string>& netlist)
{
	return netlist.size() == 3 && netlist["drain"] != "" && netlist["gate"] != "" && netlist["source"] != "";
}

void ThreeTerminal::setNetlist( map<string, string>& netlist)
{
	if (!validNetlist(netlist)) {
		printf("invalid netlist in two terminal component");
		return;
	}
	this->netlist = netlist;
}

ThreeTerminal::ThreeTerminal(const ThreeTerminal& other):Component(other)
{
}

ThreeTerminal::ThreeTerminal( string id, map<string, string>& netlist, map<string, double>& info)
	:Component(id, info)
{
	setNetlist(netlist);
}

bool ThreeTerminal::connectedTo(Component* component) const
{
	string componentID = component->getID();
	return componentID == getDrain() || componentID == getGate() || componentID == getSource();
}


void ThreeTerminal::setDrain(string terminal)
{
	setSingleNetlistTerminal("drain", terminal);
}

void ThreeTerminal::setGate(string terminal)
{
	setSingleNetlistTerminal("gate", terminal);
}
void ThreeTerminal::setSource(string terminal)
{
	setSingleNetlistTerminal("source", terminal);
}

string ThreeTerminal::getDrain() const
{
	return this->netlist.at("drain");
}

string ThreeTerminal::getGate() const
{
	return this->netlist.at("gate");
}
string ThreeTerminal::getSource() const
{
	return this->netlist.at("source");
}


