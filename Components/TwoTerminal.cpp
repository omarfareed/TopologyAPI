#include "TwoTerminal.h"

bool TwoTerminal::validNetlist(map<string, string>& netlist)
{
	return netlist.size() == 2 && netlist.count("t1") && netlist.count("t2");
}

void TwoTerminal::setNetlist(map<string, string>& netlist)
{
	setT1(netlist["t1"]);
	setT2(netlist["t2"]);
}

TwoTerminal::TwoTerminal( string id, map<string, string>& netlist, map<string, int>& info)
	:Component(id, info)
{
	if (!this->validNetlist(netlist))
	{
		printf("invalid netlist for two terminal component");
	}
}


