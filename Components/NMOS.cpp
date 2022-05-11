#include "NMOS.h"
NMOS::NMOS(string id, map<string, string>& netlist, map<string, double>& info):ThreeTerminal(id , netlist,info)
{
}

string NMOS::getType()
{
	return string();
}

void NMOS::printComponentInfo()
{
	printf("NMOS component with default value : %lf and Drain : %s, Gate : %s, Source : %s\n", this->defaultValue, this->getDrain().c_str(), this->getGate().c_str(), this->getSource().c_str());
}
