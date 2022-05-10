#include "TwoTerminal.h"

bool TwoTerminal::validNetlist(map<string, string>& netlist)
{
	return netlist.size() == 2 && netlist["t1"] != "" && netlist["t2"] != "";
}

void TwoTerminal::setNetlist(map<string, string>& netlist)
{
	if (!validNetlist(netlist)) 
	{
		printf("invalie netlist in two terminal component");
		return;
	}
	this->netlist = netlist;
}

TwoTerminal::TwoTerminal( string id, map<string, string>& netlist, map<string, double>& info)
	:Component(id, info)
{
	setNetlist(netlist);
}

bool TwoTerminal::twoTerminalComponent()
{
	return true;
}

bool TwoTerminal::threeTerminalComponent()
{
	return false;
}

void TwoTerminal::setT1(string terminal)
{
	setSingleNetlistTerminal("t1", terminal);
}

void TwoTerminal::setT2(string terminal)
{
	setSingleNetlistTerminal("t2", terminal);
}

bool TwoTerminal::connectedTo(Component* component)
{
	string componentID = component->getID();
	return componentID == getT1() || componentID == getT2();
}

string TwoTerminal::getT1()
{
	return this->netlist["t1"];
}

string TwoTerminal::getT2()
{
	return this->netlist["t2"];
}


