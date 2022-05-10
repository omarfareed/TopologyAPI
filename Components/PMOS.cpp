#include "PMOS.h"
PMOS::PMOS(string id, map<string, double>& info, map<string, string>& netlist):ThreeTerminal(id , netlist,info)
{
}

string PMOS::getType()
{
	return string();
}

void PMOS::printComponentInfo()
{
	printf("PMOS component with default value : %lf and three terminals : %s %s %s", this->defaultValue, this->getT1().c_str(), this->getT2().c_str(), this->getT3().c_str());
}