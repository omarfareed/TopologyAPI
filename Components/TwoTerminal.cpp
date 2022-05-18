#include "TwoTerminal.h"

bool TwoTerminal::validNetlist(map<string, string>& netlist)
{
	cout << netlist.size() << " " << netlist["t1"] << " " << netlist["t2"] << endl;
	return netlist.size() == 2 && netlist["t1"] != "" && netlist["t2"] != "";
}

void TwoTerminal::setNetlist(map<string, string>& netlist)
{
	if (!validNetlist(netlist)) 
	{
		printf("invalid netlist in two terminal component");
		return;
	}
	this->netlist = netlist;
}

TwoTerminal::TwoTerminal(const TwoTerminal& other):Component(other)
{
}

TwoTerminal::TwoTerminal( string id, map<string, string>& netlist, map<string, double>& info)
	:Component(id, info)
{
	setNetlist(netlist);
}


void TwoTerminal::setT1(string terminal)
{
	setSingleNetlistTerminal("t1", terminal);
}

void TwoTerminal::setT2(string terminal)
{
	setSingleNetlistTerminal("t2", terminal);
}

bool TwoTerminal::connectedTo(Component* component) const
{
	string componentID = component->getID();
	return componentID == getT1() || componentID == getT2();
}

string TwoTerminal::getT1() const
{
	return this->netlist.at("t1");
}

string TwoTerminal::getT2() const
{
	return this->netlist.at("t2");
}


