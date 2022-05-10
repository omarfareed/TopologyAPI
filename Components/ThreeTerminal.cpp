#include "ThreeTerminal.h"

bool ThreeTerminal::validNetlist( map<string, string>& netlist)
{
	return netlist.size() == 3 && netlist["t1"] != "" && netlist["t2"] != "" && netlist["t3"] != "";
}

void ThreeTerminal::setNetlist( map<string, string>& netlist)
{
	if (!validNetlist(netlist)) {
		printf("invalid netlist in two terminal component");
		return;
	}
	this->netlist = netlist;
}

ThreeTerminal::ThreeTerminal( string id, map<string, string>& netlist, map<string, int>& info)
	:Component(id, info)
{
	setNetlist(netlist);
}

void ThreeTerminal::setT1(string terminal)
{
	setSingleNetlistTerminal("t1", terminal);
}

void ThreeTerminal::setT2(string terminal)
{
	setSingleNetlistTerminal("t2", terminal);
}
void ThreeTerminal::setT3(string terminal)
{
	setSingleNetlistTerminal("t3", terminal);
}

string ThreeTerminal::getT1()
{
	return this->netlist["t1"];
}

string ThreeTerminal::getT2()
{
	return this->netlist["t2"];
}
string ThreeTerminal::getT3()
{
	return this->netlist["t3"];
}


